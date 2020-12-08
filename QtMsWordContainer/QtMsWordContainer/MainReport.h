#pragma once
class MainReport
{
public:
	MainReport();

  void InitializeData();

	void show();
private:
	class Private;
	friend class Private;
	Private& d;
};

