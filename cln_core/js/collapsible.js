
function cln_toggleCollapsible (el) {
	var bagid = el.id.replace('BTN', 'BAG');
	if (document.getElementById(bagid)) {
		var bag = document.getElementById(bagid);
		
		if (bag.className.indexOf('collapsible-collapsed') > -1) {
			bag.className = bag.className.replace('collapsible-collapsed', 'collapsible-expanded');
		} else if (bag.className.indexOf('collapsible-expanded') > -1) {
			bag.className = bag.className.replace('collapsible-expanded', 'collapsible-collapsed');
		} else {
			bag.className += ' collapsible-collapsed';
		}
	}	
}