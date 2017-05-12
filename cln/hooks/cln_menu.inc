<?php

function cln_menu () {
	$items['colony'] = array (
		'type' => MENU_NORMAL_ITEM,
		'title' => 'Colony',
		'page callback' => 'cln_pages',
		'page arguments' => array ('colony'),
		'access callback' => 'user_access',
		'access arguments' => array ('access content'),
	);
	return $items;
}

function cln_pages ($page) {
	module_load_include ('php', 'cln', 'pages/'.$page);
	$fn = 'cln_pages_'.$page;
	return $fn();
}