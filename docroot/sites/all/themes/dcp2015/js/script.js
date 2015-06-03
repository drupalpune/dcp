(function ($, Drupal) {

  Drupal.behaviors.dcp2015 = {
    attach: function (context, settings) {
      $('.pane-tweet').parent().parent().addClass('social-block');
    }
  };

})(jQuery, Drupal);
