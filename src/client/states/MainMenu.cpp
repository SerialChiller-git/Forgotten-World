#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, int& stateIndex):
    State(window),
    stateIndex(stateIndex)
{   
    this->initBackground();
    sf::Vector2f size = sf::Vector2f(window->getSize());

}

MainMenu::~MainMenu()
{

}

void MainMenu::initBackground(){
    this->background.setSize(
        sf::Vector2f
        ({
            static_cast<float>(this->window->getSize().x),
            static_cast<float>(this->window->getSize().y)
        })
    );
    if(!this->backgroundTexture.loadFromFile("assets/backgrounds/background1.jpeg")){
        throw "ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
    }
    this->background.setTexture(&this->backgroundTexture);
    // this->background.setPosition({this->window->getPosition().x/2, this->window->getPosition().y/2});

}

void MainMenu::render(sf::RenderWindow* target){
    target->setView(target->getDefaultView());
    target->draw(background);
    //std::cout << this->window->getSize().x << " " << this->window->getSize().y << "\n";
    
}

void MainMenu::update(sf::Time deltaTIme){
    this->updateMousePositions();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Num1)){
        changeState(stateIndex, 1);
    }
    //std::cout << mousePosScreen.x << " " << mousePosScreen.y << " ";
}

void MainMenu::gui(){

    sf::Vector2i size = sf::Vector2i(window->getSize());
    ImVec2 position = ImVec2(static_cast<float>(size.x/2 - 400/2), static_cast<float>(size.y/2 - 300/2));
    ImGui::SetNextWindowPos(position); // Set ImGui window position
    ImGui::SetNextWindowSize(ImVec2(400, 300));  // Set ImGui window size

    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

    ImGui::Begin("Invisible", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse);

    // Center the button
    ImVec2 windowSize = ImGui::GetWindowSize();
    ImVec2 buttonSize = ImVec2(200, 50); // Set button size
    ImVec2 buttonPos = ImVec2((windowSize.x - buttonSize.x) * 0.5f, (windowSize.y - buttonSize.y) * 0.5f);
    ImGui::SetCursorPos(buttonPos);

    // Customize button appearance
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.7f, 1.0f, 1.0f)); // Button color
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.5f, 0.8f, 1.0f, 1.0f)); // Hover color
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.6f, 0.9f, 1.0f)); // Active color

    if (ImGui::Button("Start", buttonSize)) {
        changeState(stateIndex, 1); // Calls function when clicked
    }

    ImGui::PopStyleColor(3); // Pop the three style colors
    ImGui::End();
    ImGui::PopStyleVar(2);
}

void MainMenu::processEvents(const sf::Event event){

}
