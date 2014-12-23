The Mentions module offers Twitter like functionality, recording all references
to a user's username - using the [@username] or [@#uid] filter format - from
various locations, providing a centralized page to track all mentions.

Mentions was written and is maintained by Stuart Clark (deciphered).
- http://stuar.tc/lark



Features
--------------------------------------------------------------------------------

* Tracks Mentions on any Entity.
* An Input filter to convert [@username] or [@#uid] to the user's profile.
* Customizable input ([@username], [@#uid]) and output (@username) patterns,
  including support for the Token module.
* Integrations with:
  * Machine name - Use a Machine name field as the mention source.
  * Rules - React to created, updated and deleted mentions.
  * Views - Display a list of all mentions, mentions by user, and more.



Recommended Modules
--------------------------------------------------------------------------------

* Token - http://drupal.org/project/token
* Views - http://drupal.org/project/views



Usage / Configuration
--------------------------------------------------------------------------------

Once installed, the Mentions filter needs to be enabled on your desired Text
formats, this can be done via the Text formats page.
* http://[www.yoursite.com/path/to/drupal]/admin/config/content/formats

Customisation settings for input and output patterns are available via the
Mentions configuration form:
* http://[www.yoursite.com/path/to/drupal]/admin/config/content/mentions
