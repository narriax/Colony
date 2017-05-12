<?php

function cln_pages_colony() {
	$content = '';
	if (module_exists('cln_chars') ) {
		
		$content .= l("Add a new character", 'addchar');
		
	} else $content .= '## chars not loaded';
	
	
	return $content;
	//module_load_include ('inc', 'cln_chars', 'forms/new_char_form');
	//drupal_add_css(drupal_get_path('module', 'cln').'/css/forms.css');
	
	//$new_char_form = drupal_get_form('cln_chars_new_char_form');
	//return render($new_char_form);	
}