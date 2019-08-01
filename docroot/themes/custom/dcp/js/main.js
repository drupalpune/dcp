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

  Drupal.behaviors.addActiveLink = {
    attach: function (context, settings) {
      $( window ).resize(function() {
        if(window.innerWidth > 992) {
          $('body').css('overflow', 'auto');
          $('.navigation-mobile').hide();
        }
      });
      $('.region-header .mobile-menu.trigger-icon').on('click',() => {
        $('.navigation-mobile').show();
        $('body').css('overflow', 'hidden');
      });
      $('.region-header .mobile-menu.cross-icon').on('click',() => {
        $('.navigation-mobile').hide();
        $('body').css('overflow', 'auto');
      });
    }
  };

  Drupal.behaviors.checkInput = {
    attach: function (context) {
      $('input[type="text"], input[type="email"]').each(function () {
        if ($(this).val() != "") {
          $(this).addClass("has-input");
        }
      }).on("input", function() {
        if($(this).val() != "") {
          $(this).addClass("has-input");
        }
      });
    }
  };

})(jQuery, Drupal);
