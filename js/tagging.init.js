// $Id: tagging.init.js,v 1.12.2.6 2010/10/17 10:23:24 eugenmayer Exp $

// Author: Eugen Mayer (http://kontextwork.de)
// Copyright 2010

(function ($) {
  Drupal.behaviors.tagging_d6 = function() {
    var obj = {
      attach: function() {
        $('input.tagging-widget-input:not(.tagging-processed)').tagging();
      }
    };
    obj.attach();
    return obj;
  };
  Drupal.behaviors.tagging_d7 = Drupal.behaviors.tagging_d6();
})(jQuery);