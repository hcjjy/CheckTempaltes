#include "StereoCorrelation.h"


StereoCorrelation::StereoCorrelation(QWidget *parent)
	:MyWidget(parent)
{
}


StereoCorrelation::~StereoCorrelation(void)
{
}

void StereoCorrelation::domWriteElement( QDomDocument &doc,QDomElement xmlElement, QDomElement &xmlElementRt )
{
	xmlElementRt = doc.createElement("StereoCorrelation");
	xmlElement.appendChild(xmlElementRt);
}
