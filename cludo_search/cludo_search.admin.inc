<?php
/**
 * @file
 *    admin callbacks for the Cludo module
 */

/**
 * Implements hook_admin_settings().
 *    displays the Search Cludo module settings page.
 *
 * @ingroup forms
 * @see cludo_search.helpers.inc
 * @see cludo_search_admin_settings_validate()
 * @see cludo_search_admin_settings_submit()
 */
function cludo_search_admin_settings($form) {

  // grab current settings
  $settings = _cludo_search_get_settings();

  // connection information
  $form['connection_info'] = array(
    '#title' => t('Connection Information'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE
  );
  $form['connection_info']['searchUrl'] = array(
    '#type' => 'textfield',
    '#title' => t('Your Cludo Search page'),
    '#description' => t('Valid URL or IP address of your search page, including <em>http://</em> or <em>https://. Example: <em>http://www.example.com/csearch</em>'),
    '#default_value' => $settings['searchUrl'],
    '#required' => TRUE,
  );
  $form['connection_info']['customerId'] = array(
    '#type' => 'textfield',
    '#title' => t('Customer ID'),
    '#description' => t('Cludo Search customerId value.'),
    '#default_value' => $settings['customerId'],
    '#required' => TRUE,
  );
  $form['connection_info']['engineId'] = array(
    '#type' => 'textfield',
    '#title' => t('Engine ID'),
    '#description' => t('Cludo Search engineId value.'),
    '#default_value' => $settings['engineId'],
    '#required' => TRUE,
  );

  $form['#submit'][] = 'cludo_search_admin_settings_submit';

  return system_settings_form($form);
}

/**
 * Implements hook_admin_settings_validate().
 */
function cludo_search_admin_settings_validate($form, &$form_state) {

  // searchUrl should be a valid-format URL or IPv4 address including 'http(s)://'
  if ( filter_var($form_state['values']['searchUrl'], FILTER_VALIDATE_URL) === FALSE) {
    form_set_error(
      'searchUrl',
      t('Cludo Search URL name must be a valid-format URL or IPv4 address, including <em>http(s)://</em>. Example: http://www.example.com/search.')
    );
  }
}

/**
 * Implements hook_admin_settings_submit().
 *    submit handler for admin settings
 */
function cludo_search_admin_settings_submit($form, &$form_state) {

  $field_keys =  array(
    'searchUrl',
    'customerId',
    'engineId',
  );

  // save settings
  foreach ($field_keys as $field) {
    variable_set('cludo_search_' . $field, trim($form_state['values'][$field]));
  }

  // refresh settings getter
  $settings = _cludo_search_get_settings(TRUE);

  // make the 'search_title' setting change take effect right away
  menu_rebuild();
}
