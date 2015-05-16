

function form_show(el) {
	if (!el) return;
	el.className = el.className.replace (' hidden', '');
}
function form_hide(el) {
	if (!el) return;
	if (el.className.indexOf ('hidden') < 0) {
		el.className += ' hidden';
	}
}

function form_switch_toggle (el) {
	id_on = el.name+'_'+(el.checked-0);
	id_off = el.name+'_'+(1-el.checked);
	if (document.getElementById(id_on)) {
		form_show (document.getElementById(id_on));
	}
	if (document.getElementById(id_off)) {
		form_hide (document.getElementById(id_off));
	}	
}


function form_find_parent (el, parentType, limitdepth) {
	var parent = el.parentNode;
	var counter = 0;
	while (counter < limitdepth) {
		if (parent.tagName.toUpperCase() == parentType.toUpperCase()) 
			return parent;
		parent = parent.parentNode;
		counter++;
	}
	return null;
}

function form_togglelock_find_next_step (grp) {
	var classes = grp.className.split(' ');
	for (var i=0; i<classes.length; i++) {
		if (classes[i].substr(0,5) == 'next-') {
			var id = classes[i].replace('next-', '');
			if (!document.getElementById(id)) return null;
			else return document.getElementById(id);
		}
	}
	return null;
}

function form_togglelock_step (el) {
	var grp = el.id.replace('_lock', '');
	if (!document.getElementById(grp)) return;
	grp = document.getElementById(grp);
	if (el.value == 'Lock') form_lock_step(el, grp);
	else form_reset_step(el, grp);	
}

function form_lock_step (el, grp) {
	el.value = 'Reset';
	grp.disabled = true;
	var next = form_togglelock_find_next_step(grp);
	form_show(next);
	var btn = document.getElementById(next.id+'_lock');
	if (btn) form_show(btn);	
}
function form_reset_step (el, grp) {
	el.value = 'Lock';
	grp.disabled = false;
	form_reset_following_steps (grp);
}
function form_reset_following_steps (grp) {
	var next = form_togglelock_find_next_step(grp);
	if (next == null) return;
	form_hide(next);
	var btn = document.getElementById(next.id+'_lock');
	if (btn) form_hide(btn);
	form_reset_following_steps(next);
}








