#ifndef DATA_UPLOAD_SELECTED_PARAM_PANEL_H
#define DATA_UPLOAD_SELECTED_PARAM_PANEL_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>

#include "common.h"
#include "panel.h"
#include "ui_IssueDescribe.h"
#include "common_config.h"

namespace DataUploadTool
{
	class SelectedParamPanel : public Panel
	{
		Q_OBJECT

	public:
		explicit SelectedParamPanel(QWidget *parent = 0, QString strTitle = "");

		ISSUE_DESCRIBE getIssueDescribePanelData();
		QString getIssueId();
		void initUI();
		void updateUI(ISSUE_DESCRIBE data);

	protected:
		void paintEvent(QPaintEvent *event);
		void resizeEvent(QResizeEvent *event);

	private:
		void initTitleWidget();
		void initCenterWidget();
		void initWidgetData();

	private slots:
		void cleanEstimateDateSlot();
		void cleanActualDateSlot();

	private:
		QWidget *m_topWidget;
		QWidget *m_centerWidget;
		QLabel *m_titleLabel;

		QHBoxLayout *title_layout;
		QHBoxLayout *bottom_layout;

		QString m_strTitleName;
		Ui::IssueInfoPanelClass ui;

	};

} // namespace DataUploadTool
#endif // DATA_UPLOAD_SELECTED_PARAM_PANEL_H
