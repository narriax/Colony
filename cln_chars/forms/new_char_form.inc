<?php

function cln_chars_new_char_form ($form, &$form_state) {

	// attach tool libraries
	module_load_include ('class', 'cln_core', 'tools/colors/colors');
	drupal_add_js(drupal_get_path('module', 'cln_core').'/js/forms.js');
	
	drupal_add_js(libraries_get_path('colorpicker').'/js/colorpicker.js');
	drupal_add_css(libraries_get_path('colorpicker').'/css/colorpicker.css');
	
	// TODO
	$families = array();
	
	// ================================ FAMILY
	$form['family'] = array (
		'#type' => 'fieldset',
		'#title' => 'family', 
	);
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
	$form['family']['family_reset'] = array (
		'#type' => 'button',
		'#value' => 'Reset',
		'#attributes' => array (
			'class' => array('top-right'),
		),
	);
	
	$form['parentage'] = array (
		'#type' => 'fieldset',
		'#title' => 'Parentage',
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
	
	$form['name'] = array (
		'#type' => 'textfield',
		'#size' => 30,
		'#title' => 'Name',
	);
	$form['color'] = array (
		'#type' => 'jquery_colorpicker',
		'#title' => 'Color',
		'#suffix' => '</div>',
	);	

	
	$form['gender'] = array (
		'#type' => 'radios',
		'#title' => 'Gender',
		'#options' => array ('M'=>'male', 'F'=>'female'),
	);
	
	
	return $form;
}
