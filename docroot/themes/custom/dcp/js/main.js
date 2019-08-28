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

  Drupal.behaviors.mobileMenu = {
    attach: function (context) {
      // When the page load if the current path from the menu is active then keep the parent menu expanded by default.
      $('.navigation-mobile', context).once('mobile-navigation').each(function () {
        $('.navigation-mobile #block-mainnavigation .menu-item--expanded').each(function() {
          var activeMenu = $(this).find('.is-active');
          if (activeMenu.length) {
            $(this).addClass('open');
            $(this).find('ul.menu').show();
          }
        });
      });

      $('.navigation-mobile #block-mainnavigation .menu-item--expanded > a').click(function(event) {
        // Prevent page redirection.
        event.preventDefault();
        event.stopImmediatePropagation();
        var parent = $(this).parent();
        var menuItemExpanded = $(parent).hasClass('open');
        // Lpp through all the menu item to collapsed them.
        $('.navigation-mobile #block-mainnavigation .menu-item--expanded').each(function() {
          if ($(this).hasClass('open')) {
            $(this).find('ul.menu').slideUp();;
            $(this).removeClass('open');
          }
        });
        // Expand Menu content if not expanded already.
        if (!menuItemExpanded) {
          $(parent).addClass('open');
          $(parent).find('ul.menu').slideDown();
        }
      });
    }
  };

})(jQuery, Drupal);
