(function($){
	Drupal.behaviors.highlightJSadmin = function(context) {
		
		$('#highlight-js-settings-form :disabled').each(function(){
			if ($(this).hasClass('error')) {
				// because of form cache, manually enable the field on error
				$(this).removeAttr('disabled');
			}
			else {
				$(this).parent().hide();
			}
		})
		
		$("#edit-highlight-js-theme").change(function(){
			var $theme = $('#edit-highlight-js-theme-path');
	    if ($(this).val() === '') {
	    	$theme.removeAttr('disabled');
	    	$theme.parent().show();
	    }
	    else {
	    	$theme.attr('disabled', 'disabled');
	    	$theme.parent().hide();
	    }
	     
	  })
	    
	  $('#edit-highlight-js-use-online').change(function(){
	  	var $library = $('#edit-highlight-js-local-path');
	    if ($(this).attr('checked')) {
	      $library.attr('disabled', 'disabled');
	      $library.parent().hide();
	    }
	    else {
	    	$library.removeAttr('disabled');
	    	$library.parent().show();
	    }
	  })
	}
})(jQuery);