

function form_switch_toggle (el) {
	id_on = el.name+'_'+(el.checked-0);
	id_off = el.name+'_'+(1-el.checked);
	if (document.getElementById(id_on)) {
		var div = document.getElementById(id_on);
		div.className = div.className.replace (' hidden', '');
	}
	if (document.getElementById(id_off)) {
		var div = document.getElementById(id_off);
		if (div.className.indexOf ('hidden') < 0) {
			div.className += ' hidden';
		}
	}	
}