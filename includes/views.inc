<?php
/**
 * @file
 * Views module integration.
 */

/**
 * Implements hook_views_api().
 */
function mentions_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mentions') . '/includes',
  );
}
