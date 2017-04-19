<?php

/**
 * @file
 * Defines default Rule definitions.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rules_onceperday_default_rules_configuration() {
  $rules = array();
  $rules_path = drupal_get_path('module', 'rules_onceperday') . '/default_rules';
  $files = file_scan_directory($rules_path, '/\.json$/');
  foreach ($files as $file) {
    $rule = rules_import(file_get_contents($file->uri));
    $rules[$rule->name] = $rule;
  }
  return $rules;
}
