/**
 * @file
 * Ticket type remove script.
 */

(function ($) {
  Drupal.behaviors.ticketUserRegistration = {

    attach: function($context, $settings) {
      // Load the autocomplete dropdown once on pageload
      $('#ticket-register-form').once(function(){
        $('#ticket-register-form > div > fieldset').not('#edit-ticket-registrant').prepend("<select class='registration-data-toggle' name='registration-data-toggle'><option>Autofill this form (optional)</option></select>");
        $('#ticket-register-form > div > fieldset > legend').each(function() {
          var optionName = $(this).text();
          var optionVal = $(this).parent().attr("id");
          $(".registration-data-toggle").append("<option value="+optionVal+">Copy data from "+optionName+"</option>");
        });
      });

      $('.registration-data-toggle').bind('change', function(){
        var optionName = $(this).parent().attr("id");
        var optionVal = $(this).val();

        $('#'+optionVal+' input, #'+optionVal+' select, #'+optionVal+' textarea').not('.registration-data-toggle').each(function() {
          var baseId = $(this).attr('id');
          var targetId = $(this).attr('id').replace(optionVal, optionName);
          $('#'+targetId).val($('#'+baseId).val()).trigger('change');

          if(('#'+baseId).indexOf('ticket-user-registration-email')!=-1) {
            var baseNum = ('#'+baseId).split('ticket-user-registration-email').pop();
            var targetNum = ('#'+optionName).split('edit-ticket-registrationnew-').pop();

            if(baseNum == '') {
              baseEmailId = 'edit-ticket-user-registration-email';
            }
            else {
              var baseEmailId = 'edit-ticket-registrationnew-'+baseNum+'-ticket-user-registration-email'+baseNum;
            }

            var targetEmailId = 'edit-ticket-registrationnew-'+targetNum+'-ticket-user-registration-email'+targetNum;

            $('#'+targetEmailId).val($('#'+baseEmailId).val()).trigger('keyup');
          }

        });

        $('#'+optionVal+' input[type=radio], #'+optionVal+' input[type=checkbox]').each(function() {
          var targetId = $(this).attr('id').replace(optionVal, optionName);

          if($(this).attr('checked')) {
            $('#' + targetId).attr('checked','checked');
          }

        });

      });

    }
  }
}(jQuery));
