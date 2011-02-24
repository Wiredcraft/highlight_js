(function($) {

Drupal.behaviors.highlightJS = {};
Drupal.behaviors.highlightJS.attach = function(context) {
  hljs.initHighlightingOnLoad();
};

})(jQuery);