#include "setting.h"

#include <QtWidgets>

#include "settings.h"

#include "memcheck.h"

namespace DataUploadTool
{
	DUSetting::DUSetting(DUSettings* parent) :
		QObject(parent)
	{
		//NOOP
	}

	DUSetting::DUSetting(DUSettings* owner, const QString& pDomain, const QString& pKey,
		const QVariant& pDefaultValue) :
		QObject(owner), 
		mOwner(owner), 
		mDomain(pDomain), 
		mKey(pKey), 
		mPath(pDomain + "/" + pKey), 
		mDefaultValue(pDefaultValue)
	{
		get(); // force caching of the setting
	}

	DUSetting::~DUSetting()
	{
		// NOOP
	}

	void DUSetting::set(const QVariant& pValue)
	{
		if (pValue != get())
		{
			mOwner->setValue(mPath, pValue);
			emit changed(pValue);
		}
	}

	QVariant DUSetting::get()
	{
		return mOwner->value(mPath, mDefaultValue);
	}

	QVariant DUSetting::reset()
	{
		set(mDefaultValue);
		return mDefaultValue;
	}
	
	void DUSetting::setBool(bool pValue)
	{
		set(pValue);
	}

	void DUSetting::setString(const QString& pValue)
	{
		set(pValue);
	}

	void DUSetting::setInt(int pValue)
	{
		set(pValue);
	}
}
