<?php
/**
 * @file
 * Administrative page callbacks for the highlight.js module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function highlight_js_settings_form($form_state) {
  
  $theme = variable_get('highlight_js_theme', 'default');
  $form['highlight_js_theme'] = array(
    '#type' => 'select',
    '#title' => t('Themes'),
    '#description' => t('Select a theme you would like to apply on code sections. ' 
  										. 'For more details regarding these themes, pay a visit to the !url', 
								  		array(
								  			'!url' => l('Highlight.js demo page', 'http://softwaremaniacs.org/media/soft/highlight/test.html', 
								  								array('attributes' => array('target' => '_blank')))
								  		)
								  	),
    '#default_value' => $theme,
    '#options' => array(
      'default' => 'Default',
      'dark' => 'Dark',
      'far' => 'FAR',
      'idea' => 'IDEA',
      'sunburst' => 'Sunburst',
      'zenburn' => 'Zenburn',
      'vs' => 'Visual Studio',
      'ascetic' => 'Ascetic',
      'magula' => 'Magula',
      'github' => 'Github',
      'brown_paper' => 'Brown Paper',
      'school_book' => 'School Book',
      'ir_black' => 'IR_Black',
      '' => '- Custom -'
    ),
  );
  
  $form['highlight_js_theme_path'] = array(
    '#title' => t('Custom theme path'),
    '#type' => 'textfield',
    '#default_value' => variable_get('highlight_js_theme_path', ''),
    '#disabled' => (bool) !empty($theme),
    '#description' => t('If you choose to use a custom theme you can use this setting to specify where your CSS file is located relative to the Drupal root. Leave blank if you want to load no file (may be useful if you want to define this in your Drupal theme).'),
  );

  $use_online = variable_get('highlight_js_use_online', 1);
  $form['highlight_js_use_online'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the online version of highlight.js'),
    '#description' => t('When checked, uses the online minified version of highlight.js hosted by Yandex. If unchecked, will use the files provided with the module'),
    '#default_value' => $use_online,
  );
  
  $form['highlight_js_local_path'] = array(
  	'#type' => 'textfield',
  	'#title' => t('Local path'),
    '#description' => t('The location where the Highlight.js files are located'),
  	'#default_value' => highlight_js_get_path(),
  	'#disabled' => (bool) $use_online,
  );
  
  $form['#validate'][] = '_highlight_js_admin_settings_check_path';
  
	drupal_add_js(drupal_get_path('module', 'highlight_js') .'/highlight_js.admin.js');

  return system_settings_form($form);
}

/**
 * Checks that the path specified in $form_element exists and there is a file 
 * named highlight.min.js
 * If it fails, the element if marked as having an error
 * 
 * @param $form_element
 *	The form element that contains the highlight.js path to check
 */
function _highlight_js_admin_settings_check_path($form, &$form_state) {
	$path = $form_state['values']['highlight_js_local_path'];
	$use_online = $form_state['values']['highlight_js_use_online'];
		
	if (!$use_online && (!is_dir($path) || !file_exists($path. '/highlight.min.js')) ) {
	  form_set_error('highlight_js_local_path', t('The Highlight.js library could not be found in the %path directory', 
	    array('%path' => $path)));
	}
}