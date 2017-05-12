<?php

function cln_chars_block_info () {
	$blocks = array ();
	$blocks['cln_chars_sel_family'] = array (
		'info' => ('Colony - Chars: Family selector'),
	);
	return $blocks;
}

function cln_chars_block_view ($delta='') {
	$block = array();
	switch ($delta) {
		case 'cln_chars_sel_family':
		module_load_include ('php', 'cln_chars', 'blocks/cln_chars_sel_family');
		$block['title'] = 'Select Family';
		$block['content'] = cln_chars_block_sel_family();
		break;
	}
	return $block;
}