<?php

function cln_chars_new_char_form_add_step (&$form, $step) {
	$form[$step] = array (
		'#type' => 'fieldset',
		'#title' => ucfirst($step), 
	);
	/*
	if (array_key_exists('values', $form_state)) {
		$form[$step]['#attributes']['disabled'] = true;
		$form[$step][$step.'_lock'] = array (
			'#type' => 'submit',
			'#value' => 'Reset',
			'#attributes' => array (
				'class' => array('float-top-right'),
			),
		);	
	} else { */
		$form[$step][$step.'_lock'] = array (
			'#type' => 'submit',
			'#value' => 'Lock',
			'#name' => $step.'_lock',
			'#attributes' => array (
				'class' => array('float-top-right'),
			),
		);
		//return $form;
	//}	
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


function cln_chars_new_char_form ($form, &$form_state) {

	// attach tool libraries
	module_load_include ('class', 'cln_core', 'tools/colors/colors');
	drupal_add_js(drupal_get_path('module', 'cln_core').'/js/forms.js');
	
	drupal_add_js(libraries_get_path('colorpicker').'/js/colorpicker.js');
	drupal_add_css(libraries_get_path('colorpicker').'/css/colorpicker.css');
	
	dpm($form_state);
	// TODO
	$families = array();
	
	// ================================ FAMILY
	cln_chars_new_char_form_get_step_family($form, $families);
	
	return $form;
	
	/*
	// ================================ PARENTAGE
	$form['parentage_lock'] = array (
		'#type' => 'button',
		'#value' => 'Lock',
		'#attributes' => array (
			'class' => array('float-top-right'),
			'onclick' => 'return (false);',
			'onmouseup' => 'form_togglelock_step(this);',
			'onkeyup' => 'form_togglelock_step(this);',
			'id' => 'grp_parentage_lock',
		),
	);	
	$form['parentage'] = array (
		'#type' => 'fieldset',
		'#title' => 'Parentage',
		'#attributes' => array (
			'id' => 'grp_parentage',
			'class' => array ('next-grp_personal'),
		),
	);
	$form['parentage']['father'] = array (
		'#type' => 'select',
		'#title' => 'Father',
		'#options' => array ('-'),
	);
	$form['parentage']['mother'] = array (
		'#type' => 'select',
		'#title' => 'Mother',
		'#options' => array ('-'),
	);	
	
	
	$form['personal'] = array (
		'#type' => 'fieldset',
		'#title' => 'Personal',
		'#attributes' => array (
			'id' => 'grp_personal',
			//'class' => array ('next-grp-parentage'),
		),
	);	
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
	$form['personal']['race'] = array (
		'#type' => 'select',
		'#title' => 'Race',
		'#options' => array (),
	);		
	
	return $form; */
}

function cln_chars_new_char_form_validate ($form, &$form_state) {
	$form_state['vl'] = $form_state['values'];
	form_set_error('', 'nou');
	return false;
}
function cln_chars_new_char_form_submit ($form, &$form_state) {
	form_set_error('', 'nou');
	return false;
}
