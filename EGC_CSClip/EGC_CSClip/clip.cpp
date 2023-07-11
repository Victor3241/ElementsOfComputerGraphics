#include "clip.h"

namespace egc {

	std::vector<int> computeCSCode(std::vector<vec3> clipWindow, const vec3 p) {
		std::vector<int> code;
		//TO DO - compute the code for the point given as argument
		if (clipWindow[2].y < p.y) code.push_back(1);
		else code.push_back(0);
		if (clipWindow[0].y > p.y) code.push_back(1);
		else code.push_back(0);
		if (clipWindow[2].x < p.x) code.push_back(1);
		else code.push_back(0);
		if (clipWindow[0].x > p.x) code.push_back(1);
		else code.push_back(0);
		return code;
	}

	bool simpleRejection(std::vector<int> cod1, std::vector<int> cod2) {
		//TO DO - write the code to determine if the two input codes represent 
		//points in the SIMPLE REJECTION case
		for (int i = 0; i < cod1.size(); i++) {
			if (cod1[i] == 1 && cod2[i] == 1)
				return true;
		}
		return false;
	}

	bool simpleAcceptance(std::vector<int> cod1, std::vector<int> cod2) {
		//TO DO - write the code to determine if the two input codes represent 
		//points in the SIMPLE ACCEPTANCE case
		for (int i = 0; i < cod1.size(); i++) {
			if (cod1[i] == 1 || cod2[i] == 1)
				return false;
		}
		return true;
	}

	bool inside(std::vector<int> code) {
		for (int i = 0; i < code.size(); i++) {
			if (code[i] == 1)
				return false;
		}
		return true;
	}

	//function returns -1 if the line segment cannot be clipped
	int lineClip_CohenSutherland(std::vector<vec3> clipWindow, vec3& p1, vec3& p2) {
		//TO DO - implement the Cohen-Sutherland line clipping algorithm - consult the laboratory work
		bool finish = false;
		while (finish == false) {
			std::vector<int> cod1 = computeCSCode(clipWindow, p1);
			std::vector<int> cod2 = computeCSCode(clipWindow, p2);

			if (simpleAcceptance(cod1, cod2) == true) {
				finish = true;
				return 0;
			}

			if (simpleRejection(cod1, cod2) == true) {
				finish = true;
				p1 = p2;
				return 0;
			}

			if (inside(cod1) == true) {
				vec3 aux = p1;
				p1 = p2;
				p2 = aux;
				cod1 = computeCSCode(clipWindow, p1);
				cod2 = computeCSCode(clipWindow, p2);
			}

			if (cod1[0] == 1 && p1.y != p2.y) {
				p1.x = p1.x + (p2.x - p1.x) * (clipWindow[2].y - p1.y) / (p2.y - p1.y);
				p1.y = clipWindow[2].y;
			}
			else if (cod1[1] == 1 && p1.y != p2.y) {
				p1.x = p1.x + (p2.x - p1.x) * (clipWindow[0].y - p1.y) / (p2.y - p1.y);
				p1.y = clipWindow[0].y;
			}
			else if (cod1[2] == 1 && p1.x != p2.x) {
				p1.y = p1.y + (p2.y - p1.y) * (clipWindow[2].x - p1.x) / (p2.x - p1.x);
				p1.x = clipWindow[2].x;
			}
			else if (cod1[3] == 1 && p1.x != p2.x) {
				p1.y = p1.y + (p2.y - p1.y) * (clipWindow[0].x - p1.x) / (p2.x - p1.x);
				p1.x = clipWindow[0].x;
			}
		}
		return 0;
	}
}

