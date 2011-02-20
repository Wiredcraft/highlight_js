**highlight_js** is a very simple module that provides an easy integration in Drupal of the (awesome) highlight.js script developed by Ivan Sagalaev (http://softwaremaniacs.org/soft/highlight/en/).

# Why another syntax highlighter?

There are already plenty of other solutions already available to highlight code in Drupal, however two main reasons motivated the creation of this module;

1. **highlight.js** is very practical because completely unobtrusive, to the point that you don't need to specify the language of the code you embed; the script will detect it by itself. It is particularly useful when using the Markdown filter for example, which does not allow for specifying custom attributes.
1. **highlight.js** has really straightforward and powerful theming capacities and awesome existing themes.

# Install

1. Download the archive or clone the repository.
1. Drop the *highlight_js/* folder in your modules folders (*sites/all/modules* for example)
1. Go to the modules pages (*http://yoursite.com/admin/modules*)
1. Enable the hightlight.js module.
1. Enjoy: from now on, any code you publish within <code> tags will be highlighted.

# Maintainer

- hunvreus (Ronan Berder), from Wiredcraft (http://wiredcraft.com)