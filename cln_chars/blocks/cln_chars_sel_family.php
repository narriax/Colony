<?php 


function cln_chars_block_sel_family () {
	module_load_include ('class', 'cln_core', 'api/cln_colors');
	drupal_add_js(drupal_get_path('module', 'cln_core').'/js/collapsible.js');
	drupal_add_css(drupal_get_path('module', 'cln_core').'/css/colors.css');
	drupal_add_css(drupal_get_path('module', 'cln_core').'/css/collapsible.css');
	
	$content = '';
	
	// add-new button
	$content .= '<button
					title="New Family" 
					id="BTN_new_family_pane"
					onclick="cln_toggleCollapsible(this);"
				 >+</button>';
				 
	// add-new form
	$content .= '<div id="BAG_new_family_pane" class="collapsible collapsible-collapsed">';
		$colors = new ColorSet();
		$content .= '<form method=POST>';
		$content .= 'Name: <input name="family_name"></input>';
		$content .= $colors->generateChart();
		
		$content .= 'Color: <input name="family_color"></input>';
		$content .= '<select><option><div style="background=blue;">color</div></option></select>';
		$content .= '<input type=submit value="Add" />';
		
	$content .= '</form></div>';
	
	
	return $content;
}