<?php

/**
 * Implementation of hook_rules_event_info().
 */
function onceperday_rules_event_info() {
  return array(
    'once_per_day' => array(
      'group' => t('Once per day'),
      'label' => t('Once per day'),
      'help' => t('Event fired when cron runs, but a maximum of once per day.')));
}

/**
 * Implementation of hook_rules_condition_info().
 */
function onceperday_rules_condition_info() {
  return array(
    'onceperday_condition_dayofweek' => array(
      'label' => t('Current day of the week'),
      'parameter' => array(
        'text1' => array(
          'label' => t('Day of the week is a'),
          'type' => 'integer',
          'restriction' => 'input',
          'options list' => 'onceperday_weekday_options')),
      'group' => t('Once per day'),
      'callbacks' => array(
        'execute' => 'onceperday_compare_weekday')));
}

/**
 * Callback function for rules condition options.
 */
function onceperday_weekday_options() {
  return array(
    0 => 'Sunday',
    1 => 'Monday',
    2 => 'Tuesday',
    3 => 'Wednesday',
    4 => 'Thursday',
    5 => 'Friday',
    6 => 'Saturday',
    7 => 'Working day (Monday to Friday)',
    8 => 'Weekend (Saturday or Sunday)');
}

/**
 * Callback function for rules condition test.
 */
function onceperday_compare_weekday($weekday_selected) {
  $dayofweek = date('w');
  if ($weekday_selected <= 6) {
    return $dayofweek == $weekday_selected;
  }
  elseif ($weekday_selected == 7) {
    return ($dayofweek >= 1 and $dayofweek <= 5);
  }
  elseif ($weekday_selected == 8) {
    return ($dayofweek == 0 or $dayofweek == 6);
  }
}