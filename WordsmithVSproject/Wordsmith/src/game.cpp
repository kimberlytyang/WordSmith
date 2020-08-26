#include "../header/game.hpp"

Game::Game() {
	gameWindow = new Window();
}
Game::~Game() {};

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Initialized successfully!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		if (TTF_Init() == -1) {
			std::cout << "DID NOT INIT TTF" << std::endl;
		}

		std::cout << "Drawing main menu" << std::endl;

		gameName = title;

		this->diffSelector();

		std::cout << "Initializing game..." << std::endl;

		Rectangle* background = new Rectangle(0, 0, 800, 600, 0, 130, 0);
		gameWindow->insert(background);
		Rectangle* typeboxBorder = new Rectangle(10, 290, 790, 590, 255, 255, 255);
		gameWindow->insert(typeboxBorder);
		Rectangle* typebox = new Rectangle(20, 300, 780, 580, 0, 155, 0);
		gameWindow->insert(typebox);
		Line* Underline = new Line(50, 350, 750, 350, 255, 255, 255);
		gameWindow->insert(Underline);
		Line* Underline1 = new Line(50, 400, 750, 400, 255, 255, 255);
		gameWindow->insert(Underline1);
		Line* Underline2 = new Line(50, 450, 750, 450, 255, 255, 255);
		gameWindow->insert(Underline2);
		Line* Underline3 = new Line(50, 500, 750, 500, 255, 255, 255);
		gameWindow->insert(Underline3);
		Line* Underline4 = new Line(50, 550, 750, 550, 255, 255, 255);
		gameWindow->insert(Underline4);
		
		
		srand(std::time(NULL));

		Window* prompt = new Window(0, 0, 0, 0);
		ps = new PromptSelector();
		ps->setDifficulty(this->getDiffG(diff));



		rawprompt = (rand() % 10 + 1);
		std::vector<char> vc = ps->parsePrompt(rawprompt);

		gameWindow->draw(renderer);

		std::vector<std::string>d{ "(Novice)", "(Intermediate)", "(Advanced)", "(Scrambled)", "(Campaign)", "(Ranked)" };
		std::cout << "Gamemode: " << d.at(diff) << std::endl;
		this->drawString(d.at(diff), 0, 50, 255, 255, 255, 20);

		std::cout << "Prompt selected: ";
		Flyweight* fw = new Flyweight();

		int len = 0;
		int line = 0;
		for (unsigned i = 0; i < vc.size(); ++i) {
			std::cout << vc.at(i);
			Character* temp = fw->hash(vc.at(i));
			if (temp->getC() != '/') {
				temp->setLocation(50 + len, 325 + (line * 50));
			}
			else {
				temp->setLocation(50 + len, 325 + (line * 50));
				line += 1;
				len = -17;
				//continue;
			}
			temp->setColor(255, 255, 255);
			prompt->insert(temp);
			temp->draw(renderer);
			len += 17;
		}
		gameWindow->insert(prompt);

		this->drawString("WORDSMITH", 0, 0, 255, 255, 255, 40);
		isRunning = true;
		this->drawString("PRESS ENTER TO BEGIN", 7, 150, 255, 255, 255, 25);
		
	}
	else {
		isRunning = false;
	}
}

void Game::handleEvents() {
	tick++;
	//std::cout << "tick: " << tick << std::endl;
	this->cycleImage("slow");
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	case SDL_KEYDOWN:
		const char* kp = SDL_GetKeyName(event.key.keysym.sym);
		//std::cout << "here!";
		if (strcmp(kp, "Return") == 0) {
			if (gameStart) {
				break;
			}
			int len = 0;
			int line = 0;
			Flyweight* fw = new Flyweight();
			vector<char> vc = ps->parsePrompt(rawprompt);
			//int currChar = 0;
			gameStart = true;
			while (gameStart) {

				bool found = false;
				time = clock();
				int currtime = clock() - time;
				timeblock = new Rectangle(0, 150, 400, 290, 0, 130, 0);
				this->updateTimer(renderer, currtime / CLOCKS_PER_SEC);
				while (!found) {
					currtime = clock() - time;
					//std::cout << currtime / CLOCKS_PER_SEC << std::endl;
					if (ptime < currtime / CLOCKS_PER_SEC) {
						this->updateTimer(renderer, currtime / CLOCKS_PER_SEC);
						std::cout << "UPDATING..." << std::endl;
					}
					SDL_Event event1;
					SDL_PollEvent(&event1);
					switch (event1.type) {
					case SDL_KEYDOWN:
						const char* kp1 = SDL_GetKeyName(event1.key.keysym.sym);
						//cout << *kp1;
						if (strcmp(kp1, "Left Shift") == 0 || strcmp(kp1, "Right Shift") == 0) {
							//this->updateTimer(renderer, currtime / CLOCKS_PER_SEC);
							SDL_Event eventShift;
							SDL_PollEvent(&eventShift);
							if (eventShift.type == SDL_KEYDOWN) {
								const char* shiftKey = SDL_GetKeyName(eventShift.key.keysym.sym);
								if ((vc.at(currChar) == *shiftKey)&&(isupper(vc.at(currChar)))) {
									//std::cout << "Match " << vc.at(currChar) << std::endl;

									this->fill(fw, len, line, vc.at(currChar),0);
									
									break;
								} else if(vc.at(currChar) != *shiftKey && isupper(vc.at(currChar)) && strcmp(shiftKey, "Left Shift") != 0 && strcmp(shiftKey, "Right Shift") != 0){
									//std::cout << "159" << std::endl;
									//++mistakes;
									break;
								} else {
									break;
								}
							}
						} else {
							if (vc.at(currChar) == ' ') {
								if (strcmp(kp1, "Space") == 0) {
									this->fill(fw, len, line, vc.at(currChar),0);
									break;
								}
								std::cout << "172" << std::endl;
									++mistakes;
							} else if (vc.at(currChar) == '/') {
								if (strcmp(kp1, "Space") == 0) {
									this->fill(fw, len, line, vc.at(currChar), 0);////
									line++;
									len = 0;
									break;
								}

							} else if (vc.at(currChar) == '.') {
								if (strcmp(kp1, ".") == 0) {
									this->fill(fw, len, line, vc.at(currChar),0);
									break;
								}
									++mistakes;
							} else if (vc.at(currChar) == '\'') {
								if (strcmp(kp1, "'") == 0) {
									this->fill(fw, len, line, vc.at(currChar),0);
									break;
								}
									++mistakes;
							} else if (vc.at(currChar) == '?') {
								if (strcmp(kp1, "?") == 0) {
									this->fill(fw, len, line, vc.at(currChar),0);
									break;
								}
								++mistakes;
							} else if (vc.at(currChar) == ':') {
								if (strcmp(kp1, ":") == 0) {
									this->fill(fw, len, line, vc.at(currChar),0);
									break;
								}
								++mistakes;
							} else if (vc.at(currChar) == '"') {
								if (strcmp(kp1, "\"") == 0) {
									this->fill(fw, len, line, vc.at(currChar),0);
									break;
								}
								++mistakes;
							} else if (vc.at(currChar) == ',') {
								if (strcmp(kp1, ",") == 0) {
									this->fill(fw, len, line, vc.at(currChar),0);
									break;
								}
								++mistakes;
							}
							if (toupper(vc.at(currChar)) == *kp1 && islower(vc.at(currChar))) {
								this->fill(fw, len, line, vc.at(currChar), 0);
							}
							else {
								//std::cout << "no match " << toupper(vc.at(currChar)) << " " << tolower(*kp1);
								++mistakes;
							}
						}
						break;
						found = true;
					}
					if (currChar >= vc.size()) {
						Window* scorespage = new Window();
						Rectangle* border = new Rectangle(190, 90, 542, 510, 255, 255, 255);
						scorespage->insert(border);
						Rectangle* r = new Rectangle(200, 100, 532, 500, 0, 140, 0);
						scorespage->insert(r);
						scorespage->draw(renderer);
						drawString("PRESS ENTER TO RESTART", 300, 0, 255, 255, 255, 20);
						drawString("PRESS q TO QUIT", 300, 50, 255, 255, 255, 20);
						drawString("Past games", 202, 90, 255, 255, 255, 50);
						Statistics* s = new Statistics();
						std::cout << "Updating stats" << std::endl;
						s->readStats();
						//std::cout << "Add stats" << std::endl;
						s->addStats(diff, WPM, Accuracy);
						//std::cout << "get stats" << std::endl;
						vector<string> stats = s->getStatsFormatted();
						//std::cout << "write stats" << std::endl;
						s->writeStats();
						int xstat = 202;
						int ystat = 160;
						std::cout << "writing" << std::endl;
						int count = 0;
						for (int i = stats.size()-1; i >= 0 ; --i) {
							if (count == 15) {
								break;
							}
							drawString(stats.at(i), xstat, ystat, 255, 255, 255, 13);
							ystat += 20;
							++count;
						}

						if (diff == 4) {
							ParseCampaign* p = new ParseCampaign();
							p->incrementProgress();
						}
						else if (diff == 5) {
							ParseRanked* pr = new ParseRanked();
							pr->calculateScore(WPM, Accuracy);
							pr->updateRating();
							std::cout << "New Rating: " << pr->getUserRating() << std::endl;
						}

						while (true) {
							SDL_Event restart;
							SDL_PollEvent(&restart);
							tick++;
							this->cycleImage("slow");
							if (restart.type == SDL_KEYDOWN) {
								//std::cout << "226" << std::endl;
								const char* kp = SDL_GetKeyName(restart.key.keysym.sym);	
								if (strcmp(kp, "Return") == 0) {
									//std::cout << "230" << std::endl;
									break;
								}
								else if (strcmp(kp, "Q") == 0) {
									//std::cout << "234" << std::endl;
									isRunning = false;
									return;
								}
							}
						}
						this->clean();

						Game* newGame = new Game();
						newGame->init(("New" + gameName).c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
						while (newGame->running()) {
							newGame->handleEvents();
						}
						newGame->clean();
						return;
					}
				}
			}
			//isRunning = false;
		}
		else {
			//Character* c = new Character(*kp, 50 + length, 325, 255, 255, 255);
			//c->draw(renderer);
			//gameWindow->insert(c);
			//length += 20;
		}
		break;
	}
}

void Game::updateTimer(SDL_Renderer* r, int t) {
	ptime = t;
	this->cycleImage("ig");
	timeblock->draw(r);

	int x = 7;
	int y = 150;

	string stime = to_string(t) + " seconds";

	this->drawString(stime, x, y, 255, 255, 255, 30);
	y += 50;



	int wpm = (currChar / 5.5) / (ptime/60.0);
	std::cout << "WPM:" << wpm << std::endl;
	WPM = wpm;
	string wpmString = to_string(wpm) + " WPM";
	if (t == 0) {
		wpmString = "0 WPM";
		wpm = 0;
	}
	this->drawString(wpmString, x, y, 255, 255, 255, 30);

	y += 50;

	std::cout << "MISTAKES: " << mistakes << std::endl;
	int accuracy = ((currChar*1.0) /( (mistakes*1.0) + (currChar*1.0))) * 100.0;
	Accuracy = accuracy;
	std::cout << "ACCURACY: " << accuracy << std::endl;
	string accString = to_string(accuracy) + "% Accuracy";
	if (t == 0 || currChar == 0) {
		accString = "100% Accuracy";
	}
	this->drawString(accString, x, y, 255, 255, 255, 30);

}

void Game::diffSelector() {
	while (true) {
		Rectangle* background = new Rectangle(0, 0, 800, 600, 0, 130, 0);
		background->draw(renderer);
		this->drawString("Select game mode with the number keys", 5, 0, 255, 255, 255, 20);
		this->drawString("Enter to confirm", 5, 30, 255, 255, 255, 20);
		this->drawString("s to view game history", 5, 60, 255, 255, 255, 20);
		this->drawString("q to quit", 5, 90, 255, 255, 255, 20);
		this->drawString("1) Novice", 5, 150, 255, 255, 255, 30);
		this->drawString("2) Intermediate", 5, 200, 255, 255, 255, 30);
		this->drawString("3) Advanced", 5, 250, 255, 255, 255, 30);
		this->drawString("4) Scrambled", 5, 300, 255, 255, 255, 30);
		this->drawString("5) Campaign", 5, 350, 255, 255, 255, 30);
		this->drawString("6) Ranked", 5, 400, 255, 255, 255, 30);
		Window* w = new Window();
		Line* n = new Line(38, 190, 137, 190, 0, 0, 0);
		w->insert(n);
		Line* i = new Line(40, 240, 230, 240, 255, 255, 255);
		w->insert(i);
		Line* a = new Line(40, 290, 180, 290, 255, 255, 255);
		w->insert(a);
		Line* s = new Line(40, 340, 190, 340, 255, 255, 255);
		w->insert(s);
		Line* c = new Line(40, 392, 172, 392, 255, 255, 255);
		w->insert(c);
		Line* r = new Line(40, 440, 150, 440, 255, 255, 255);
		w->insert(r);
		this->drawImage("res/start.jpg", 600, 0, 200, 200);
		bool notChose = false;
		int choice = 0;
		while (!notChose) {
			w->draw(renderer);
			SDL_Event arrow;
			SDL_PollEvent(&arrow);

			if (arrow.type == SDL_KEYDOWN) {
				const char* ak = SDL_GetKeyName(arrow.key.keysym.sym);
				if (strcmp(ak, "1") == 0) {
					w->getChild(choice)->setColor(255, 255, 255);
					choice = 0;
					w->getChild(choice)->setColor(0, 0, 0);
				}
				else if (strcmp(ak, "2") == 0) {
					w->getChild(choice)->setColor(255, 255, 255);
					choice = 1;
					w->getChild(choice)->setColor(0, 0, 0);
				}
				else if (strcmp(ak, "3") == 0) {
					w->getChild(choice)->setColor(255, 255, 255);
					choice = 2;
					w->getChild(choice)->setColor(0, 0, 0);
				}
				else if (strcmp(ak, "4") == 0) {
					w->getChild(choice)->setColor(255, 255, 255);
					choice = 3;
					w->getChild(choice)->setColor(0, 0, 0);
				}
				else if (strcmp(ak, "5") == 0) {
					w->getChild(choice)->setColor(255, 255, 255);
					choice = 4;
					w->getChild(choice)->setColor(0, 0, 0);
				}
				else if (strcmp(ak,"6") == 0){
					w->getChild(choice)->setColor(255, 255, 255);
					choice = 5;
					w->getChild(choice)->setColor(0, 0, 0);
				} 
				else if (strcmp(ak, "Return") == 0) {
					diff = choice;
					//std::cout << "CHOICE" << std::endl;
					return;
				} else if (strcmp(ak, "Q") == 0) {
					this->clean();
					exit(0);
				} else if (strcmp(ak, "S") == 0) {
					std::cout << "Opening statistics page" << std::endl;
					this->statsPage();
					break;
				}

			}
		}
	}
	
}

void Game::statsPage() {
	//std::cout << "399" << std::endl;
	Window* w = new Window();
	Rectangle* background = new Rectangle(0, 0, 800, 600, 0, 140, 0);
	w->insert(background);
	Rectangle* underline = new Rectangle(5, 65, 400, 75, 255, 255, 255);
	w->insert(underline);
	w->draw(renderer);
	this->drawString("GAME HISTORY", 5, 2, 255, 255, 255, 50);
	this->drawString("Press q to quit", 550, 2, 255, 255, 255, 30);
	this->drawString("Press c to clear", 550, 50, 255, 255, 255, 30);
	Statistics* s = new Statistics();
	s->readStats();
	vector<string> v = s->getStatsFormatted();
	//std::cout << "Writing stats" << std::endl;
	//s->writeStats();
	
	//std::cout << "411" << std::endl;
	int x = 5;
	int y = 70;
	int cap = 0;
	for (int i = v.size() - 1; i >= 0; --i) {
		if (cap == 20) {
			break;
		}
		this->drawString(v.at(i), x, y, 255, 255, 255, 20);
		x += 0;
		y += 20;
		++cap;
	}
	while (true) {
		SDL_Event q;
		SDL_PollEvent(&q);
		if (q.type == SDL_KEYDOWN) {
			const char* quit = SDL_GetKeyName(q.key.keysym.sym);
			if (strcmp(quit, "Q") == 0) {
				break;
			} else if (strcmp(quit, "C") == 0) {
				std::cout << "Clearing stats!" << std::endl;
				s->clearStats();
				s->readStats();
				Rectangle* clear = new Rectangle(0, 75, 549, 600, 0, 140, 0);
				clear->draw(renderer);
			}
		}
	}
	return;
}

void Game::drawString(string s, int x, int y, int r, int g, int b, int f) {
	TTF_Font* font = TTF_OpenFont("res/comic.ttf", f);
	SDL_Color color = { r,g,b };
	SDL_Surface* surface = TTF_RenderText_Solid(font, s.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { x, y, texW, texH };
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	SDL_RenderPresent(renderer);
}

void Game::fill(Flyweight* fw, int &len, int line, char ch, int cy) {
	if (cy == 0) {
		this->cycleImage("ig");
	}
	Character* c = fw->hash(ch);
	c->setLocation(50 + len, 325 + (line * 50));
	c->setColor(0, 0, 0);
	c->draw(renderer);
	++currChar;
	len+=17;
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Quit!" << std::endl;
}

bool Game::running() {
	return isRunning;
}

Parse* Game::getDiffG(int i) {
	if (i == 0) {
		return new ParseNovice();
	}
	else if (i == 1) {
		return new ParseIntermediate();
	}
	else if (i == 2) {
		return new ParseAdvanced();
	}
	else if (i == 3) {
		return new ParseRandom();
	}
	else if (i == 4) {
		return new ParseCampaign();
	}
	else if(i == 5) {
		return new ParseRanked();
	}
	else {
		return nullptr;
	}
}

void Game::drawImage(string s, int x, int y, int w, int h) {
	SDL_Texture* img;
	SDL_Surface* tempSurface = IMG_Load(s.c_str());
	img = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	int texW = w;
	int texH = h;
	SDL_Rect dstrect = { x,y,texW,texH};
	
	SDL_RenderCopy(renderer, img, NULL, &dstrect);
	SDL_RenderPresent(renderer);
}

void Game::cycleImage(string s) {
	if (s == "slow") {
		if (tick % 50000 == 0) {
			std::vector<string> path{ "res/1.jpg", "res/2.jpg", "res/3.jpg", "res/4.jpg",  "res/5.jpg",  "res/6.jpg",  "res/7.jpg",  "res/8.jpg",  "res/9.jpg",  "res/10.jpg", "res/11.jpg",  "res/12.jpg" };
			frame++;
			this->drawImage(path.at(frame % 11), 550, 50, 200, 200);
		}
	} else if(s == "ig"){
		std::vector<string> path{ "res/1.jpg", "res/2.jpg", "res/3.jpg", "res/4.jpg",  "res/5.jpg",  "res/6.jpg",  "res/7.jpg",  "res/8.jpg",  "res/9.jpg",  "res/10.jpg", "res/11.jpg",  "res/12.jpg" };
	    frame++;
	    this->drawImage(path.at(frame % 11), 550, 50, 200, 200);
	}
}