//N16051079 §d«a¹F HW02
#ifndef HW02_H_
#define HW02_H_
class Point
{
	private: //#1 
		float x;
		float y;
	public: 
		Point();//#2 
		Point(float, float);//#3 
		~Point();//#4 
		void Set_data(float, float);//#5 
		float operator[](int i)const;//#6 
		friend std::istream & operator >> (std::istream&, Point&);//#7 
		friend std::ostream & operator<<(std::ostream&, const Point&);//#8
};

class QuadtreeNode
{
private: const Point* data; //#9 
		 QuadtreeNode* nextNode[4]; //#10 
		 const Point separate_point; //#11 
		 const float size;//#12 
<<<<<<< HEAD
public: //QuadtreeNode()=delete;//#13 
=======
public: QuadtreeNode()=delete;//#13 
>>>>>>> f76a06fac7a85804f7b31306bb811cd48dd02808
		QuadtreeNode(const Point&, const Point&, const float);//#14 
		QuadtreeNode(const QuadtreeNode&);//#15 
		~QuadtreeNode();//#16 
		bool InsertPoint(const Point&);//#17 
<<<<<<< HEAD
		const Point FindClosestPoint(const Point&)const;//#18 
=======
		void FindClosestPoint(const Point&)const;//#18 
>>>>>>> f76a06fac7a85804f7b31306bb811cd48dd02808
};


#endif


