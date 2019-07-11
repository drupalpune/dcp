/**
 * @file
 * custom js.
 */

(function ($, Drupal) {
  'use strict';

  Drupal.behaviors.address = {
    attach: function (context, settings) {
      $('.animate-odometer').each(function() {
        if (!$(this).hasClass('once')) {
          $(this).addClass('once');
          var self = this;
          var val = $(this).html();
          var format = val.indexOf('%') !== -1 ? 'ddd%' : 'ddd';
          var odometer = new Odometer({
            el: self,
            value: 0,
            format: format,
            theme: 'default'
          });
          odometer.update(val);
        }
    });
  }
};

})(jQuery, Drupal);
