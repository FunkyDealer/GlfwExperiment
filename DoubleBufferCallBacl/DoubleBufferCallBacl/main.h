#pragma once
using namespace std;

namespace application {
	   
	class App {

	private:
		int counter_;

	public:
		App() {
			counter_ = 0;
		}

		void update() {
			cout << "test " << counter_ << endl;

			counter_++;
		}

	};
}