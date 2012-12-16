<?php
/**
 * @file
 * Rules module integration.
 */

/**
 * Implements hook_rules_data_info().
 */
function mentions_rules_data_info() {
  return array(
    'mention' => array(
      'label' => t('mention'),
      'group' => t('Mentions'),
      'wrap' => TRUE,
      'property info' => array(
        'mid' => array(
          'type' => 'decimal',
          'label' => t('Mention ID'),
        ),
        'entity_type' => array(
          'type' => 'text',
          'label' => t('Mention source entity type')
        ),
        'entity' => array(
          'type' => 'entity',
          'label' => t('Mention source entity')
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('Mentioned user'),
        ),
        'author' => array(
          'type' => 'user',
          'label' => t('Mention author user'),
        ),
        'created' => array(
          'type' => 'date',
          'label' => t('Created date'),
        ),
        'updated' => array(
          'type' => 'date',
          'label' => t('Updated date'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_event_info().
 */
function mentions_rules_event_info() {
  $items = array();

  $items['mentions_insert'] = array(
    'label' => t('After a new mention is created'),
    'group' => t('Mentions'),
    'variables' => array(
      'mention' => array(
        'label' => t('Mention'),
        'type' => 'mention',
      ),
    ),
  );

  $items['mentions_update'] = array(
    'label' => t('After a mention is updated'),
    'group' => t('Mentions'),
    'variables' => array(
      'mention' => array(
        'label' => t('Mention'),
        'type' => 'mention',
      ),
    ),
  );

  $items['mentions_delete'] = array(
    'label' => t('After a mention is deleted'),
    'group' => t('Mentions'),
    'variables' => array(
      'mention' => array(
        'label' => t('Mention'),
        'type' => 'mention',
      ),
    ),
  );

  return $items;
}

/**
 * Implements hook_mentions_insert() on behalf of rules.module
 */
function rules_mentions_insert($mention) {
  mentions_rules_invoke_event('mentions_insert', $mention);
}

/**
 * Implements hook_mentions_update() on behalf of rules.module
 */
function rules_mentions_update($mention) {
  mentions_rules_invoke_event('mentions_update', $mention);
}

/**
 * Implements hook_mentions_delete() on behalf of rules.module
 */
function rules_mentions_delete($mention) {
  mentions_rules_invoke_event('mentions_delete', $mention);
}

/**
 * Helper function; Prepare mention object and invoke Rules event.
 */
function mentions_rules_invoke_event($event, $mention) {
  // Load source entity object.
  $entities = entity_load($mention->entity_type, array($mention->entity_id));
  $mention->entity = isset($entities[$mention->entity_id]) ? $entities[$mention->entity_id] : NULL;
  unset($mention->entity_id);

  // Load mentioned user object.
  $mention->user = user_load($mention->mentioned_uid);
  unset($mention->mentioned_uid);

  // Load author user object.
  $mention->author = user_load($mention->author_uid);
  unset($mention->author_uid);

  rules_invoke_event($event, $mention);
}
