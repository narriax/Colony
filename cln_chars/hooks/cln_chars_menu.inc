<?php

function cln_chars_menu () {
	$items['chars'] = array (
		'type' => MENU_NORMAL_ITEM,
		'title' => 'Characters',
		'page callback' => 'cln_chars_pages',
		'page arguments' => array ('chars'),
		'access callback' => 'user_access',
		'access arguments' => array ('access content'),
	);	
	$items['chars/addchar'] = array (
		'type' => MENU_NORMAL_ITEM,
		'title' => 'Add New Character',
		'page callback' => 'cln_chars_pages',
		'page arguments' => array ('addchar'),
		'access callback' => 'user_access',
		'access arguments' => array ('access content'),
	);
	return $items;
}

function cln_chars_pages ($page) {
	module_load_include ('php', 'cln_chars', 'pages/'.$page);
	$fn = 'cln_chars_pages_'.$page;
	return $fn();
}