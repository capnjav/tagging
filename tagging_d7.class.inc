<?php

class tagging_d7 extends tagging_d6 {

  private static $theme = null;

  public function hook_menu() {
    $items = parent::menu();
    $items['admin/config/content/tagging'] = $items['admin/settings/tagging/settings'];
    unset($items['admin/settings/tagging/settings']);
    return $items;
  }

  public function hook_theme() {
    if (!tagging_d7::$theme) {
      $theme = parent::theme();
      foreach ($theme as $key => $arr) {
        $arr['variables'] = $arr['arguments'];
        unset($arr['arguments']);
        $theme[$key] = $arr;
      }
      tagging_d7::$theme = $theme;
    }
    return tagging_d7::$theme;
  }

  public function theme_tagging_widget($args) {
    return parent::theme_tagging_widget_button($args['element']);
  }

  public function theme_tagging_widget_button($args) {
    return parent::theme_tagging_widget_button($args['vid']);
  }

  public function theme_tagging_widget_wrapper($args) {
    return parent::theme_tagging_widget_wrapper($args['content']);
  }

  public function theme_tagging_tags_list($args) {
    return parent::theme_tagging_tags_list($args['content'], $args['vid']);
  }

  public function theme_tagging_suggestions_list($args) {
    return parent::theme_tagging_suggestions_list($args['suggestions'], $args['vid']);
  }

  /**
   * call $this->theme('my_theme_name', $arg1, $arg2) [Drupal 6 Style] and the funciton will construct a proper argument array for the Drupal 7 theme function as if you would call theme('my_theme_name', array('arg1' => $arg1, 'arg2' => $arg2))
   * @return <type>
   */
  public function theme() {
    $args = func_get_args();
    return call_user_func_array('theme', $args);
    /*
    $args = func_get_args();
    $theme_name = array_shift($args);
    $theme = $this->hook_theme();
    if (isset($theme[$theme_name])) {
      $theme_arg_array = $theme[$theme_name]['variables'];
      foreach ($theme_arg_array as $key => $value) {
        if (!empty($args)) {
          $theme_arg_array[$key] = array_shift($args);
        } else {
          break;
        }
      }
      return theme($theme_name, $theme_arg_array);
    }*/
  }

}