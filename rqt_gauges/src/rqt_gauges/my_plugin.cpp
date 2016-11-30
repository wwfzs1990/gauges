
#include <pluginlib/class_list_macros.h>
#include <QStringList>
#include "rqt_gauges/my_plugin.h"
#include "rqt_gauges/qcgaugewidget.h"

namespace rqt_gauges {

MyPlugin::MyPlugin()
  : rqt_gui_cpp::Plugin()
  , widget_(0)
{
  // Constructor is called first before initPlugin function, needless to say.

  // give QObjects reasonable names
  setObjectName("MyPlugin");
}

void MyPlugin::initPlugin(qt_gui_cpp::PluginContext& context)
{
  // access standalone command line arguments
  QStringList argv = context.argv();
  // create QWidget
  mSpeedGauge_ = new QcGaugeWidget();
  //widget_ = new QWidget();
  widget_ = mSpeedGauge_;
  // extend the widget with all attributes and children from UI file
  ui_.setupUi(widget_);

  // Set up the gauge
  mSpeedGauge_->addBackground(99);

  // add widget to the user interface
  context.addWidget(widget_);
}

void MyPlugin::shutdownPlugin()
{
  // TODO unregister all publishers here
}

void MyPlugin::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
{
  // TODO save intrinsic configuration, usually using:
  // instance_settings.setValue(k, v)
}

void MyPlugin::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
{
  // TODO restore intrinsic configuration, usually using:
  // v = instance_settings.value(k)
}

/*bool hasConfiguration() const
{
  return true;
}

void triggerConfiguration()
{
  // Usually used to open a dialog to offer the user a set of configuration
}*/

} // namespace
PLUGINLIB_DECLARE_CLASS(rqt_gauges, MyPlugin, rqt_gauges::MyPlugin, rqt_gui_cpp::Plugin)
