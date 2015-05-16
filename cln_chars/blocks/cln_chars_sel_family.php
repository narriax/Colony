<?php 


function cln_chars_block_sel_family () {
	
	// attach core libraries
	drupal_add_js(drupal_get_path('module', 'cln_core').'/js/collapsible.js');
	drupal_add_css(drupal_get_path('module', 'cln_core').'/css/collapsible.css');
	
	// attach forms
	module_load_include ('inc', 'cln_chars', 'forms/new_char_form');
	
	$content = '';
	
	// add-new button
	$content .= '<button
					title="New Family" 
					id="BTN_new_family_pane"
					onclick="cln_toggleCollapsible(this);"
				 >+</button>';
				 
	// add-new form
	//$new_char_form = drupal_get_form('cln_chars_new_char_form');
	$content .= '<div id="BAG_new_family_pane" class="collapsible collapsible-collapsed">';
	//$content .= render($new_char_form);
		
		/*$colors = new ColorSet();
		$content .= '<form method=POST>';
		$content .= 'Name: <input name="family_name"></input>';
		
		//$content .= 'Color: <input name="family_color" id="color"></input>';
		$content .= $colors->generateChart();
		
		$content .= '<select><option><div style="background=blue;">color</div></option></select>';
		$content .= '<input type=submit value="Add" />';
		*/
		
	$content .= '</form></div>';
	return $content;
}