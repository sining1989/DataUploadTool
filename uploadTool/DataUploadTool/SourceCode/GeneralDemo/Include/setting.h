#ifndef DATA_UPLOAD_SETTING_H_
#define DATA_UPLOAD_SETTING_H_

#include <QtWidgets>

namespace DataUploadTool
{
	class DUSettings;

	class DUSetting : public QObject
	{
		Q_OBJECT

		public:
			DUSetting(DUSettings* parent = 0);
			DUSetting(DUSettings* owner, const QString& pDomain, const QString& pKey,
							const QVariant& pDefaultValue);

			virtual ~DUSetting();

			virtual void set(const QVariant& pValue);
			virtual QVariant get();
			virtual QVariant reset();

			virtual QString domain() const
			{
				return mDomain;
			}

			virtual QString key() const
			{
				return mKey;
			}

			virtual QString path() const
			{
				return mPath;
			}

			virtual QVariant defaultValue() const
			{
				return mDefaultValue;
			}

		public slots:

			void setBool(bool pValue);
			void setString(const QString& pValue);
			void setInt(int pValue);

		signals:

			void changed(QVariant newValue);

		protected:

			DUSettings* mOwner;
			QString mDomain;
			QString mKey;
			QString mPath;
			QVariant mDefaultValue;
	};


} // namespace DataUploadTool

#endif /* DATA_UPLOAD_SETTING_H_ */
