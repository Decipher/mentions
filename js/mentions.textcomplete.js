(function ($) {
  Drupal.behaviors.mentionsTextcomplete = {
    attach: function () {
      var settings = Drupal.settings.mentions.textcomplete;
      var matchExp = new RegExp('\\B' + settings.prefix_regex + '(\\w*)$');

      $.each(settings.forms, function (index, form) {
        $(form).textcomplete([
          {
            match: matchExp,
            search: function (term, callback) {
              $.getJSON(Drupal.settings.basePath + 'mentions/autocomplete/' + term, function (resp) {
                callback(resp);
              });
            },
            replace: function (mention) {
              return settings.prefix + mention + settings.suffix + ' ';
            },
            index: 1
          }
        ]);
      });
    }
  }
})(jQuery);
