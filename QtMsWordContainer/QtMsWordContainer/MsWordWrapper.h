#pragma once
#include <QWidget>

class MsWordWrapper : public QWidget
{
    
public:
  MsWordWrapper( QWidget* parent = Q_NULLPTR );

  void OpenFile( QString filename );


};
