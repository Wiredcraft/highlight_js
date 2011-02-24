<?php
/**
 * @file
 * Administrative page callbacks for the highlight.js module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 * TODO Add option to specify the path under sites/all/libraries
 *      This will help keep the modules dir clean and make it easier on Drupal
 */
function highlight_js_settings_form($form_state) {
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
    '#default_value' => variable_get('highlight_js_theme', 'default'),
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
    '#states' => array(
      // Only show this field when the theme is set to custom.
      'visible' => array(
        ':input[name="highlight_js_theme"]' => array('value' => ''),
      ),
    ),
    '#description' => t('If you choose to use a custom theme you can use this setting to specify where your CSS file is located relative to the Drupal root. Leave blank if you want to load no file (may be useful if you want to define this in your Drupal theme).'),
  );

  $form['highlight_js_use_online'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the online version of highlight.js'),
    '#description' => t('When checked, uses the online minified version of highlight.js hosted by Yandex. If unchecked, will use the files provided with the module'),
    '#default_value' => variable_get('highlight_js_use_online', 1),
  );

  return system_settings_form($form);
}