<?php
/**
 * @file
 * Administration and configuration files.
 */

/**
 * Administration settings form.
 */
function rules_onceperday_settings_form($form, &$form_state) {
  $form = array();
  $form['help'] = array(
    '#markup' => t('The Once per Day module causes a Rules event to be triggered once, and only once, each day. It also provides a Rules condition to require a day of the week, month, or quarter, for less-frequent actions.'),
    '#prefix' => '<p>',
    '#suffix' => '</p>');

  $last_triggered = state_get('rules_onceperday_last');
  if ($last_triggered) {
    $last_triggered = format_date($last_triggered, 'long');
  }
  else {
    $last_triggered = 'Not yet triggered';
  }
  $form['last'] = array(
    '#type' => 'item',
    '#title' => t('Last Triggered'),
    '#markup' => $last_triggered,
  );
  if (state_get('rules_onceperday_last') != NULL) {
    $form['reset'] = array(
      '#type' => 'submit',
      '#value' => t('Reset last-triggered date'),
      '#submit' => array(
        'rules_onceperday_reset'));
  }

  $form['hour'] = array(
    '#type' => 'select',
    '#title' => t('Trigger Hour'),
    '#description' => t('The rules event will be triggered the first time cron runs in or after this hour.'),
    '#options' => range(0, 23),
    '#default_value' => config_get('rules_onceperday.settings', 'hour'),
  );

  $form['show_examples'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include Examples'),
    '#description' => t('Uncheck this and flush the cache to remove the example rules from the Rules listing.'),
    '#default_value' => config_get('rules_onceperday.settings', 'show_examples'),
  );

  $form['#config'] = 'rules_onceperday.settings';
  return system_settings_form($form);
}


/**
 * Reset function called from administration settings form.
 */
function rules_onceperday_reset() {
  state_del('rules_onceperday_last');
}
