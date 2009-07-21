<?php
// $Id$
/**
 * @file
 * Field handler to present mention content.
 */
class mentions_views_handler_field_content extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['body'] = array('table' => 'node_revisions', 'field' => 'body');
    $this->additional_fields['format'] = array('table' => 'node_revisions', 'field' => 'format');
    $this->additional_fields['comment'] = array('table' => 'comments', 'field' => 'comment');
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $this->field_alias = is_null($values->{$this->aliases['comment']}) ? $this->aliases['body'] : $this->aliases['comment'];

    $value = $values->{$this->field_alias};
    $format = $values->{$this->aliases['format']};

    return check_markup($value, $format, FALSE);
  }

  function element_type() {
    if (isset($this->definition['element type'])) {
      return $this->definition['element type'];
    }

    return 'div';
  }
}
