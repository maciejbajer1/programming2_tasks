#include <iostream>
#include <string>
using namespace std;

class PLAYER_CLASS;
class CAESAR_CLASS;
class ARENA_CLASS;
class HUMAN_CLASS;
class BEAST_CLASS;
class BERSERKER_CLASS;
class SQUAD_CLASS;


class PLAYER_CLASS {
    friend class CAESAR_CLASS;
    friend class SQUAD_CLASS;

protected:
    virtual void die () {
        currentHealth = 0;
    }

public:
    unsigned int maxHealth;
    unsigned int currentHealth;
    unsigned int attack;
    unsigned int agility;

    PLAYER_CLASS(unsigned int maxH = 0, unsigned int currH = 0, unsigned int att = 0, unsigned int agi = 0) : maxHealth(maxH), currentHealth(currH), attack(att), agility(agi) {};
    virtual unsigned int getRemainingHealth () = 0;
    virtual unsigned int getDamage() = 0;
    virtual unsigned int getAgility () = 0;
    virtual void takeDamage (unsigned int damage) = 0;
    virtual void applyWinnerReward () = 0;
    virtual void cure () = 0;
    virtual void printParams () = 0;
    virtual unsigned int getDefence (){
        return 1;
    }
    virtual string getId (){
        return "";
    }
    virtual unsigned int getMaxHp (){
        return 1;
    }
    virtual unsigned int getCurrHp (){
        return 1;
    }
};

class CAESAR_CLASS {
public:
    int numOfJudements;
    CAESAR_CLASS(){
        numOfJudements = 0;
    };
    void judgeDeathOrLife(PLAYER_CLASS *player){
        numOfJudements++;
        if (numOfJudements % 3 == 0){
            player->die();
            numOfJudements = 0;
        }
    };
};

class ARENA_CLASS{
private:
    CAESAR_CLASS *caesar;
public:
    ARENA_CLASS(CAESAR_CLASS* caesar) : caesar(caesar) {};

    void fight(PLAYER_CLASS *player1 , PLAYER_CLASS *player2){
        if (player1->getRemainingHealth() == 0 || player2->getRemainingHealth() == 0) return;
        PLAYER_CLASS *p1;
        PLAYER_CLASS *p2;
        if(player1->getAgility() > player2->getAgility()){
            p1 = player1;
            p2 = player2;
        }
        else if (player1->getAgility() < player2->getAgility()){
            p1 = player2;
            p2 = player1;
        }
        else{
            p1 = player1;
            p2 = player2;
        }
        p1->printParams();
        p2->printParams();
        int numOfAttacks = 0;
        while (true){

            if (p1->getRemainingHealth() > 0){
                p2->takeDamage(p1->getDamage());
                numOfAttacks++;
                p2->printParams();
            }

            if (numOfAttacks == 40 || p1->getRemainingHealth() < 10 || p2->getRemainingHealth() < 10){
                break;
            }

            if (p2->getRemainingHealth() > 0){
                p1->takeDamage(p2->getDamage());
                numOfAttacks++;
                p1->printParams();
            }

            if (numOfAttacks == 40 || p1->getRemainingHealth() < 10 || p2->getRemainingHealth() < 10){
                break;
            }
        }

        if (p1->getRemainingHealth() > 0){
            if (numOfAttacks % 2 == 0){
                caesar->judgeDeathOrLife(p1);
            }
            p1->printParams();
        }
        if (p2->getRemainingHealth() > 0){
            if (numOfAttacks % 2 == 0){
                caesar->judgeDeathOrLife(p2);
            }
            p2->printParams();
        }

        if(p1->getRemainingHealth() > 0){
            p1->applyWinnerReward();
            p1->cure();
        }
        if(p2->getRemainingHealth() > 0){
            p2->applyWinnerReward();
            p2->cure();
        }
        p1->printParams();
        p2->printParams();

    }
};

class HUMAN_CLASS : public virtual PLAYER_CLASS {
private:
    string id;
public:
    unsigned int defence;

    HUMAN_CLASS(string idH) : PLAYER_CLASS(200, 200, 30, 10), id(idH), defence(10) {};

    virtual unsigned int getCurrHp (){
        return currentHealth;
    }
    string getId (){
        return id;
    }
    unsigned int getDefence (){
        return defence;
    }
    unsigned int getRemainingHealth (){
        return (currentHealth * 100) / maxHealth;
    }
    void applyWinnerReward () {
        attack += 2;
        agility += 2;
    }
    void cure (){
        currentHealth = maxHealth;
    }
    unsigned int getAgility (){
        return agility;
    }
    unsigned int getDamage (){
        return attack;
    }
    void takeDamage (unsigned int damage){

        unsigned int temp = (damage - (defence + agility));
        if ((defence + agility) > damage) return;

        bool in = false;
        if (currentHealth <= temp){
            in = false;
        }
        else{
            in = true;
        }

        if (in){
            currentHealth = currentHealth - temp;
        }
        else{
            die();
        }
    }
    void printParams (){
        if (getRemainingHealth() != 0){
            cout << id << ":" << maxHealth << ":" << currentHealth << ":" << getRemainingHealth() << "%:" << attack << ":" << agility << ":" << defence << endl;
        }
        else{
            cout << id << ":R.I.P." << endl;
        }
    }
};

class BEAST_CLASS : public virtual PLAYER_CLASS{
private:
    string id;
public:
    BEAST_CLASS(string idB) : PLAYER_CLASS(150, 150, 40, 20), id(idB) {};

    virtual unsigned int getCurrHp (){
        return currentHealth;
    }
    unsigned int getMaxHp () {
        return maxHealth;
    };
    string getId (){
        return id;
    }
    unsigned int getDefence (){
        return 0;
    }
    unsigned int getRemainingHealth (){
        return (currentHealth * 100) / maxHealth;
    }
    void applyWinnerReward () {
        attack += 2;
        agility += 2;
    }
    void cure (){
        currentHealth = maxHealth;
    }
    unsigned int getAgility () {
        return agility;
    }
    unsigned int getDamage() {
        if (getRemainingHealth() < 25){
            return (2 * attack);
        }
        else{
            return attack;
        }
    }
    void takeDamage (unsigned int damage) {
        unsigned int temp = (damage - (agility / 2));
        if ((agility / 2) > damage) return;
        bool in = false;
        if (currentHealth <= temp){
            in = false;
        }
        else {
            in = true;
        }
        if (in) {
            currentHealth = currentHealth - temp;
        }
        else{
            die();
        }
    }
    void printParams () {
        if (getRemainingHealth() != 0){
            cout << id << ":" << maxHealth << ":" << currentHealth << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << agility << endl;
        }
        else{
            cout << id << ":R.I.P." << endl;
        }
    }
};

class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS{
public:
    BERSERKER_CLASS(string idH, string idB) : PLAYER_CLASS(200, 200, 35, 5), HUMAN_CLASS(idH), BEAST_CLASS(idB)
    {
        defence = 15;
    };

    virtual unsigned int getCurrHp (){
        if (getRemainingHealth() == 0 || getRemainingHealth() >= 25){
            return HUMAN_CLASS::getCurrHp();
        }
        else{
            return BEAST_CLASS::getCurrHp();
        }
    }
    unsigned int getMaxHp (){
        if (getRemainingHealth() == 0 || getRemainingHealth() >= 25){
            return HUMAN_CLASS::getMaxHp();
        }
        else{
            return BEAST_CLASS::getMaxHp();
        }
    }
    string getId (){
        if (getRemainingHealth() == 0 || getRemainingHealth() >= 25){
            return HUMAN_CLASS::getId();
        }
        else{
            return BEAST_CLASS::getId();
        }
    }
    unsigned int getDefence (){
        return defence;
    }
    void die (){
        currentHealth = 0;
    }
    unsigned int getRemainingHealth (){
        return (currentHealth * 100) / maxHealth;
    }
    void applyWinnerReward () {
        attack += 2;
        agility += 2;
    }
    void cure (){
        currentHealth = maxHealth;
    }
    void takeDamage(unsigned int damage){
        if (getRemainingHealth() == 0 || getRemainingHealth() >= 25){
            HUMAN_CLASS::takeDamage(damage);
        }
        else{
            BEAST_CLASS::takeDamage(damage);
        }
    }
    unsigned int getDamage (){
        if (getRemainingHealth() == 0 || getRemainingHealth() >= 25){
            return HUMAN_CLASS::getDamage();
        }
        else{
            return BEAST_CLASS::getDamage();
        }
    }
    unsigned int getAgility (){
        if (getRemainingHealth() == 0 || getRemainingHealth() >= 25){
            return HUMAN_CLASS::getAgility();
        }
        else{
            return BEAST_CLASS::getAgility();
        }
    }
    void printParams (){
        if (getRemainingHealth() == 0 || getRemainingHealth() >= 25){
            HUMAN_CLASS::printParams();
        }
        else{
            BEAST_CLASS::printParams();
        }
    }
};

class SQUAD_CLASS : public virtual PLAYER_CLASS {
public:
    struct Node {
        PLAYER_CLASS *player;
        Node *next;
        Node(PLAYER_CLASS *p) : player(p), next(NULL) {};
    };

    Node *head;
    string id;
    int numOfplayers;

    SQUAD_CLASS(string id_) : PLAYER_CLASS(0, 0, 0, 0), id(id_), head(NULL), numOfplayers(0) {}
    void addPlayer (PLAYER_CLASS* player)
    {
        if (player->getRemainingHealth() == 0) return;
        Node *curr = head;
        while (curr != NULL){
            if (curr->player == player){
                return;
            }
            curr = curr->next;
        }
        Node *newNode = new Node(player);
        numOfplayers++;
        if (head == NULL){
            head = newNode;
        }
        else{
            Node *curr = head;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    };
    unsigned int getAgility (){
        if (head == NULL) return 0;
        Node *curr = head;
        unsigned int agility = curr->player->getAgility();
        curr = curr->next;
        while (curr != NULL){
            unsigned int temp = curr->player->getAgility();
            if (temp < agility){
                agility = temp;
            }
            curr = curr->next;
        }
        return agility;
    }
    unsigned int getDamage (){
        if (head == NULL) return 0;
        Node *curr = head;
        unsigned int sumOfDamage = curr->player->getDamage();
        curr = curr->next;
        while (curr != NULL){
            sumOfDamage += curr->player->getDamage();
            curr = curr->next;
        }
        return sumOfDamage;
    }
    void takeDamage(unsigned int damage) {
        Node *curr = head;
        while(curr != NULL) {
            curr->player->takeDamage(damage / numOfplayers);
            curr = curr->next;
        }

        curr = head;
        while (curr != NULL) {
            if (curr->next == NULL && curr == head && curr->player->getCurrHp() == 0){
                numOfplayers--;
                head = NULL;
                break;
            }
            if (curr == head && curr->player->getCurrHp() == 0){
                head = head->next;
                numOfplayers--;
            }
            else if (curr->player->getCurrHp() == 0) {
                numOfplayers--;
                Node *toDelete = curr;
                Node *curr2 = head;
                bool last = false;
                if (toDelete->next == NULL){
                    last = true;
                }
                while (curr2->next != toDelete) {
                    curr2 = curr2->next;
                }
                if (last){
                    curr2->next = NULL;
                }
                else{
                    curr2->next = curr2->next->next;
                }
            }
            curr= curr->next;
        }
    }
    unsigned int getRemainingHealth (){
        if (head == NULL){
            return 0;
        }
        Node *curr = head;
        unsigned int maxHp = curr->player->getRemainingHealth();
        curr = curr->next;
        while (curr != NULL){
            unsigned int temp = curr->player->getRemainingHealth();
            if (temp > maxHp){
                maxHp = temp;
            }
            curr = curr->next;
        }
        return maxHp;
    }
    void cure (){
        Node *curr = head;
        while (curr != NULL){
            curr->player->cure();
            curr = curr->next;
        }
    }
    void applyWinnerReward (){
        Node *curr = head;
        while (curr != NULL){
            curr->player->applyWinnerReward();
            curr = curr->next;
        }
    }
    void die (){
        Node *curr = head;
        while (curr != NULL){
            curr->player->die();
            curr = curr->next;
        }
        numOfplayers = 0;
        head = NULL;
    }
    void sort(Node *&head2) {
        if (head2 == NULL) return;
        bool swapped;
        Node *p1;
        Node *p2 = NULL;

        do {
            swapped = false;
            p1 = head2;

            while (p1->next != p2) {
                if (!comparePlayers(p1->player, p1->next->player)) {

                    swapPlayers(p1, p1->next);
                    swapped = true;
                }
                p1 = p1->next;
            }
            p2 = p1;
        } while (swapped);
    }
    bool comparePlayers(PLAYER_CLASS *a, PLAYER_CLASS *b) {
        if (a->getId() != b->getId())
            return (a->getId() < b->getId());
        if (a->getMaxHp() != b->getMaxHp())
            return (a->getMaxHp() < b->getMaxHp());
        if (a->getCurrHp() != b->getCurrHp())
            return (a->getCurrHp() < b->getCurrHp());
        if (a->getRemainingHealth() != b->getRemainingHealth())
            return (a->getRemainingHealth() < b->getRemainingHealth());
        if (a->getDamage() != b->getDamage())
            return (a->getDamage() < b->getDamage());
        return (a->getAgility() < b->getAgility());
    }
    void printParams ()     {

        if (numOfplayers > 0) {
            cout << id << ":" << numOfplayers << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << getAgility() << endl;

            sort(head);
            Node *curr = head;
            while (curr != NULL){
                curr->player->printParams();
                curr = curr->next;
            }
        }
        else{
            cout << id << ":" << "nemo" << endl;
        }
    }
    void swapPlayers(Node* node1, Node* node2) {
        PLAYER_CLASS* tempPlayer = node1->player;
        node1->player = node2->player;
        node2->player = tempPlayer;
    }


};
