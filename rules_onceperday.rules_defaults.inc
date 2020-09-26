<?php
/**
 * @file
 * Default Rules.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rules_onceperday_default_rules_configuration() {

  $config = array();
  if (config_get('rules_onceperday.settings', 'show_examples')) {
    $rules_path = backdrop_get_path('module', 'rules_onceperday') . '/default_rules';
    $files = file_scan_directory($rules_path, '/\.json$/');
    foreach ($files as $filepath => $file) {
      $rule = backdrop_json_decode(file_get_contents($filepath));
      if (!empty($rule)) {
        $config['rules_onceperday_' . $file->name] = rules_import($rule);
      }
    }
  }
  return $config;
}
