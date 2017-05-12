<?php

function cln_chars_new_char_form_add_step (&$form, $step) {
	$form[$step.'_reset'] = array (
		'#type' => 'submit',
		'#value' => 'Reset',
		'#name' => $step.'_reset',
		'#attributes' => array (
			'class' => array('float-top-right button-reset'),
		),
	);
	$form[$step] = array (
		'#type' => 'fieldset',
		'#title' => ucfirst($step), 
	);
	$form[$step][$step.'_lock'] = array (
		'#type' => 'submit',
		'#value' => 'Lock',
		'#name' => $step.'_lock',
		'#attributes' => array (
			'class' => array('float-top-right button-lock'),
		),
	);	
}


function cln_chars_forms_get_saved_value ($form, $step, $valuekey) {
	if (!isset($_SESSION['colony']) 
			|| !isset($_SESSION['colony'][$form]) 
			|| !isset($_SESSION['colony'][$form][$step])
			|| !isset($_SESSION['colony'][$form][$step][$valuekey])) {
		return null;
	} else {
		return $_SESSION['colony']['new_char'][$step][$valuekey];
	}
}


function cln_chars_new_char_form ($form, &$form_state) {

	// attach tool libraries
	module_load_include ('class', 'cln', 'tools/colors/colors');
	drupal_add_js(drupal_get_path('module', 'cln').'/js/forms.js');
	
	if (module_exists('jquery_colorpicker')) {
		drupal_add_js(libraries_get_path('colorpicker').'/js/colorpicker.js');
		drupal_add_css(libraries_get_path('colorpicker').'/css/colorpicker.css');
	} else {
		form_set_error('', 'ERROR: must have [Jquery Colorpicker] module and associated libraries installed and enabled.');
		return $form;
	}
	
	// attach class libraries
	module_load_include ('class', 'cln_chars', 'api/cln_demographic');
	$dem = new cln_demographic();
	$dem_tree = $dem->get_tree();
	dpm($dem_tree);
	
	// fixme: remove
	$body_set = $dem->get_bodytypes();
	$species_set = array();
	if ($bodytype = cln_chars_forms_get_saved_value ('new_char', 'parentage', 'parentage_bodytype')) {
		$species_set = $dem->get_species($body_set[$bodytype]);
	}
	
	// TODO
	$families = array();
	$family = cln_chars_forms_get_saved_value ('new_char', 'family', 'family_existing');
	$males = array();
	$females = array();
	$father = cln_chars_forms_get_saved_value ('new_char', 'parentage', 'father');
	$mother = cln_chars_forms_get_saved_value ('new_char', 'parentage', 'mother');
	
	// ================================ create form
	cln_chars_new_char_form_get_step_family($form, $families);
	cln_chars_new_char_form_get_step_parentage ($form, $body_set, $males, $females);
	cln_chars_new_char_form_get_step_personal ($form, $father, $mother, $species_set);

	// ================================ check for completitions
	$completed_steps = array ();
	foreach ($form as $step => $data) {
		if (strpos($step, '_reset') !== false) continue;
		$completed_steps[$step] = false;
	}
	if (isset($_SESSION['colony']['new_char'])) {
		foreach ($completed_steps as $step => $data) {
			if (array_key_exists($step, $_SESSION['colony']['new_char'])) {
				$completed_steps[$step] = true;
			}
		}
	}
	
	// ================================ pull data from completitions
	$skiped_one = false;
	foreach ($completed_steps as $step => $completed) {
		if ($completed) {
			if (!array_key_exists('#attributes', $form[$step])) $form[$step]['#attributes'] = array();
			$form[$step]['#attributes']['disabled'] = true;
			unset($form[$step][$step.'_lock']);
			
			foreach ($_SESSION['colony']['new_char'][$step] as $key => $value) {
				$form[$step][$key]['#value'] = $value;
			}
		} else {
			unset($form[$step.'_reset']);
			if ($skiped_one) unset($form[$step]);
			else $skiped_one = true;
		}
	}
	
	return $form; 
}

function cln_chars_new_char_form_validate ($form, &$form_state) {
	$btn = explode('_',$form_state['clicked_button']['#name']);
	$btn_step = $btn[0];
	$btn_type = $btn[1];
	
	if (!array_key_exists('colony', $_SESSION)) $_SESSION['colony'] = array();
	if (!array_key_exists('new_char', $_SESSION['colony'])) $_SESSION['colony']['new_char'] = array();
	if ($btn_type == 'reset') {
		$steps = array_reverse($_SESSION['colony']['new_char']);
		foreach ($steps as $step => $data) {
			unset($_SESSION['colony']['new_char'][$step]);
			if ($step == $btn_step) break;
		}
	} else {
		foreach ($form_state['values'] as $key => $value) {
			if (strpos($key, $btn_step) === 0) {
				$_SESSION['colony']['new_char'][$btn_step][$key] = $value;
			}
		}
	}
}
function cln_chars_new_char_form_submit ($form, &$form_state) {

}



function cln_chars_new_char_form_get_step_family (&$form, $families) {
	cln_chars_new_char_form_add_step($form, 'family');
	
	$form['family']['family_switcher'] = array (
		'#type' => 'checkbox',
		'#default_value' => 1,
		'#title' => 'New',
		'#prefix' => '<div class=switcher-switch>',
		'#suffix' => '</div>',
		'#attributes' => array (
			'onchange' => 'form_switch_toggle(this);',
		),
	);	
	$form['family']['family_new'] = array (
		'#type' => 'textfield',
		'#size' => 30,
		'#title' => 'Family',
		'#prefix' => '<div class="switcher-bag" id="family_switcher_1">',
	);
	$form['family']['family_new_color'] = array (
		'#type' => 'jquery_colorpicker',
		'#title' => 'Color',
		'#suffix' => '</div>',
	);
	$form['family']['family_existing'] = array (
		'#type' => 'select',
		'#title' => 'Family',
		'#options' => $families,
		'#prefix' => '<div class="switcher-bag hidden" id="family_switcher_0">',
		'#suffix' => '</div>',
	);
}


function cln_chars_new_char_form_get_step_parentage (&$form, $bodies, $males, $females) {
	// todo: fetch chars

	cln_chars_new_char_form_add_step($form, 'parentage');
	$form['parentage']['parentage_bodytype'] = array (
		'#type' => 'select',
		'#title' => 'Body type',
		'#options' => $bodies,
	);	
	$form['parentage']['parentage_father'] = array (
		'#type' => 'select',
		'#title' => 'Father',
		'#options' => array_merge(array (0=>'-'),$males),
	);
	$form['parentage']['parentage_mother'] = array (
		'#type' => 'select',
		'#title' => 'Mother',
		'#options' => array_merge(array (0=>'-'),$females),
	);		
}


function cln_chars_new_char_form_get_step_personal (&$form, $father, $mother, $species_set) {
	$species = array();
	$dem_tree = array();
	foreach($species_set as $sid => $s) {
		$species[$sid] = $s->name;
		
	}

	cln_chars_new_char_form_add_step($form, 'personal');
	$form['personal']['name'] = array (
		'#type' => 'textfield',
		'#size' => 30,
		'#title' => 'Name',
	);
	$form['personal']['color'] = array (
		'#type' => 'jquery_colorpicker',
		'#title' => 'Color',
		'#suffix' => '</div>',
	);		
	$form['personal']['gender'] = array (
		'#type' => 'radios',
		'#title' => 'Gender',
		'#options' => array ('M'=>'male', 'F'=>'female'),
	);
	$form['personal']['species'] = array (
		'#type' => 'select',
		'#title' => 'Species',
		'#options' => $species,
		'#prefix' => '<div>',
	);
	$form['personal']['race'] = array (
		'#type' => 'select',
		'#title' => 'Race',
		'#options' => array (),
	);	
	$form['personal']['subrace'] = array (
		'#type' => 'select',
		'#title' => 'Subrace',
		'#options' => array (),
	);
	$form['personal']['ethnicity'] = array (
		'#type' => 'select',
		'#title' => 'Ethnicity',
		'#options' => array (),
		'#suffix' => '</div>',
	);			
}