#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
// начало файла обънетов и сущностей 
//первичная сущность это год, дальше месяц, неделя, день, час
/*

	день
		-год( функиця доступа к родителю)
		-неделя (меньше данных, можно уместить в чар)
		-task
		-suptask

		+вывод дня ->общие задачи на день -> вывод часов и задачей в часах



*/

class DateEssence {
	private:
		std::string name;
		int numunit;
	public:
		void print (){
			std::cout<<"приветики пистолетики"<<std::endl;
			std::cout<<name<<"\t"<<numunit<<std::endl;
		}
	DateEssence(std::string name){
		std::transform(name.begin(), name.end(), name.begin(), tolower);
		this->name = name;
		this->numunit = (this->name == "feb")?28:30;
		return;
	}
};



int main(int argc, char const *argv[])
{	
	std::string name;
	std::cin>>name;
	DateEssence var(name);
	var.print();
	std::time_t moment = std::time(0);
	std::tm *datw=std::localtime(&moment);
	std::cout<<std::ctime(&moment)<<std::endl;
	std::cout<<"go go"<<1900 + datw->tm_year<<":"<<datw->tm_mon<<":"<<datw->tm_yday<<std::endl;
	return 0;
}