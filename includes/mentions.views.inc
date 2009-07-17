<?php
// $Id$
/**
 * @file
 * Contains views data and handlers for the Mentions module.
 */

/**
 * Implementation of hook_views_handlers().
 */
function mentions_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'mentions') .'/includes',
    ),
    'handlers' => array(
      'mentions_views_handler_field_user_name' => array(
        'parent' => 'views_handler_field_user_name',
      ),
      'mentions_views_handler_field_title' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function mentions_views_data() {
  $data['mentions']['table']['group']  = t('Mentions');

  $data['mentions']['table']['base'] = array(
    'field' => 'uid',
    'title' => t('Mentions'),
    'help' => t('References made to @username.'),
    'weight' => 10,
  );

  // Mention user id.
  $data['mentions']['uid'] = array(
    'title' => t('User'),
    'help' => t('The user mentioned.'),
    'field' => array(
      'handler' => 'mentions_views_handler_field_user_name',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Mention author id.
  $data['mentions']['auid'] = array(
    'title' => t('Author'),
    'help' => t("The name of the mention's author."),
    'field' => array(
      'handler' => 'mentions_views_handler_field_user_name',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Mention timestamp.
  $data['mentions']['timestamp'] = array(
    'title' => t('Date'),
    'help' => t("The date of the mention."),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Mention title.
  $data['mentions']['title'] = array(
    'field' => array(
      'title' => t('Title'),
      'help' => t('The title of the mention.'),
      'handler' => 'mentions_views_handler_field_title',
    ),
  );

  return $data;
}

function mentions_views_data_alter(&$data) {
  $data['node']['table']['join']['mentions'] = array(
    'left_table' => 'mentions',
    'left_field' => 'nid',
    'field' => 'nid',
  );
  $data['comments']['table']['join']['mentions'] = array(
    'left_table' => 'mentions',
    'left_field' => 'cid',
    'field' => 'cid',
  );
}
