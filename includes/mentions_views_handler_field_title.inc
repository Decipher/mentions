<?php
// $Id$
/**
 * @file
 * Field handler to present a link to mention.
 */
class mentions_views_handler_field_title extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['cid'] = 'cid';
    $this->additional_fields['title'] = array('table' => 'node', 'field' => 'title');
    $this->additional_fields['subject'] = array('table' => 'comments', 'field' => 'subject');
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_mention'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Provide link to mention option
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_mention'] = array(
      '#title' => t('Link this field to the mention'),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_mention']),
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render whatever the data is as a link to the node.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_mention']) && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "node/" . $values->{$this->aliases['nid']};
      $this->options['alter']['alt'] = check_plain($data);
      if (!is_null($values->{$this->aliases['cid']})) {
        $this->options['alter']['fragment'] = 'comment-'. $values->{$this->aliases['cid']};
      }
    }
    return $data;
  }

  function render($values) {
    $title = (is_null($values->{$this->aliases['cid']}))
      ? $values->{$this->aliases['title']}
      : $values->{$this->aliases['subject']};

    return $this->render_link(check_plain($title), $values);
  }
}
