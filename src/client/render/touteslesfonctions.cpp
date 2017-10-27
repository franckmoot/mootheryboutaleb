

#include "render/CharsTileSet.h"
#include "render/GridTileSet.h"
#include "render/Tile.h"
#include "render/Tilemap.h"
#include "state/Batiment.h"
#include "state/Champdebataille.h"
#include "state/Element.h"
#include "state/ElementChars.h"
#include "state/ElementTab.h"
#include "state/MobileElement.h"
#include "state/StaticElement.h"
#include "state/Infanterie.h"
#include "state/Tank.h"
#include "state/Heli.h"

using namespace std;
using namespace state;
using namespace render;


CharsTileSet::CharsTileSet() {
    
    infanterie.push_back(*(new Tile(36,0,16,30)));
    infanterie.push_back(*(new Tile(36,0,16,16)));
    infanterie.push_back(*(new Tile(36,0,16,16)));
    tank.push_back(*(new Tile(109,0,16,16)));
    tank.push_back(*(new Tile(109,0,16,16)));
    heli.push_back(*(new Tile(216,16,16,30)));
    heli.push_back(*(new Tile(216,32,16,16))); 
    
  }
  
  
  const std::string CharsTileSet::getImageFile() const {
    return "res/player.png";
  }
  
  
  const Tile& CharsTileSet::getTile(const state::Element& e) const {
    
    if(!e.isStatic()){
      MobileElement* mobileTmp = (MobileElement*)&e;
      
      if(mobileTmp->getTypeId()==INFANTERIE){     
	
	return infanterie[MVTATTENTE];
	
      }else if (mobileTmp->getTypeId()==TANK){
	
	return tank[MVTATTENTE2];
	
      }else if( mobileTmp->getTypeId()==HELI){
	
	return heli[MVTATTENTE1];
      }
    }
    return infanterie[MVTATTENTE];
  }

   GridTileSet::GridTileSet() {
    
    chpbataille.push_back(*(new Tile(0,0,16,16)));
    chpbataille.push_back(*(new Tile(16,0,16,16)));
    chpbataille.push_back(*(new Tile(32,0,16,16)));
    chpbataille.push_back(*(new Tile(48,0,16,16)));
    chpbataille.push_back(*(new Tile(64,0,16,16)));
    batiment.push_back(*(new Tile(0,16,16,30)));
    batiment.push_back(*(new Tile(16,32,16,16))); 
  }
  
  
  const std::string GridTileSet::getImageFile() const {
    return "res/tilemap.png";
  }
  
  
  const Tile& GridTileSet::getTile(const state::Element& e) const {

    if(e.isStatic()){
      StaticElement* staticTmp = (StaticElement*)&e;
      
      if(staticTmp->isChampdebataille()){
	Champdebataille* champTmp = (Champdebataille*)&e;
	
	switch (champTmp->getChampdeBatailleType()){
	  
	case EAU:
	  return chpbataille[EAU];
	  break;
	  
	case HERBE:     
	  return chpbataille[HERBE];
	  break;
	  
	case ROCHER:
	  return chpbataille[ROCHER];
	  break;
          
	case ROUTE:
	  return chpbataille[ROUTE];
	  break;
          
	case SABLE:
	  return chpbataille[SABLE];
	  break;
          
	default:
	  return chpbataille[0];
	  break;
	}
      }else if (!staticTmp->isChampdebataille()){
        
	Batiment* batTmp=(Batiment*)&staticTmp;
	
	switch (batTmp->getBatimentTypeId()){
	  
	case CASERNE:
	  return batiment[CASERNE];
	  break;
	  
	case QG:    
	  return batiment[CASERNE];
	  break;
          
	default:
	  return batiment[0];
	  break;
	}
	
      }
    }
    
    return chpbataille[0];
  }
  
     Tile::Tile(int x, int y, int w, int h) {
        this->x=x;
        this->y=y;
        this->width=w;
        this->height=h;  
    }
   
    int Tile::getHeight() const {
        return height;
    }

    int Tile::getWidth() const {
        return width;
    }
    int Tile::getX() const {
        return x;
    }

    int Tile::getY() const {
        return y;
    }

    void Tile::setHeight(int height) {
        this->height=height;
    }

    void Tile::setWidth(int width) {
        this->width=width;
    }

    void Tile::setX(int x) {
        this->x=x;
    }

    void Tile::setY(int y) {
        this->y=y;
    }
    
    
       Batiment::Batiment() {

    }

    Batiment::Batiment(BatimentTypeId id) {
        
        if (id == BatimentTypeId::CASERNE ) this->setType( BatimentTypeId::CASERNE);
        if (id == BatimentTypeId::QG ) this->setType(BatimentTypeId::QG);
                    
    }



    TypeId Batiment::getTypeId() const {
        return TypeId::BATIMENT;
    }

    
    /* Getter de capture */
    int Batiment::getCapture() const {
            return capture;
    }
    
    /* Setter de capture */
    void Batiment::setCapture(int capture) {
        this->capture=capture;
    }

    /* Differenci le champdebataille au batiment*/
    bool Batiment::isChampdebataille() const {
        return false;
    }

    
    /* Getter de BatimentTypeId */
    BatimentTypeId Batiment::getBatimentTypeId() const {
        return batimentTypeId;
    }
    
    
     Champdebataille::Champdebataille() {

    }
    
    Champdebataille::Champdebataille(ChampdebatailleTypeId id) {

        if (id == ChampdebatailleTypeId::EAU ) this->setType( ChampdebatailleTypeId::EAU );
        if (id == ChampdebatailleTypeId::HERBE ) this->setType( ChampdebatailleTypeId::HERBE );
        if (id == ChampdebatailleTypeId::ROCHER ) this->setType( ChampdebatailleTypeId::ROCHER );
        if (id == ChampdebatailleTypeId::ROUTE ) this->setType( ChampdebatailleTypeId::ROUTE );
        if (id == ChampdebatailleTypeId::SABLE ) this->setType( ChampdebatailleTypeId::SABLE );
    }

    Champdebataille::~Champdebataille() {

    }


    
   ChampdebatailleTypeId Champdebataille::getChampdeBatailleType() const {
        return champdeBatailleType;
    }


    bool Champdebataille::isChampdebataille() const {
        return true;
    }

    TypeId Champdebataille::getTypeId() const {
           return TypeId::CHAMPSDEBATAILLE;
    }
    
    
    
     Element::Element() {}

    Element::~Element() {}
        
    int Element::getType() {
        return type;
    }

    void Element::setType(int type) {
        this->type=type;
    }
    
    void Element::setTypeId(TypeId typeId) {
        this->typeId=typeId;
    }
    
    
    ElementChars::ElementChars() {

    }
    
    
    
    
    ElementTab::ElementTab() {
       
    }
    
    ElementTab::ElementTab(size_t width, size_t height) {
            vector<unique_ptr<Element> > list(width*height);
    }
    
    int ElementTab::sizeList() {
        return list.size();
    }

    
    void ElementTab::setElement( Element* e) {
        list.push_back(unique_ptr<Element>(e));
    }
    
    Element *  ElementTab::getElement(int i, int j) const {

           return list[i*j].get();
    }
    
 
    size_t ElementTab::getHeight() {
        return height;
    }
    
    size_t ElementTab::getWidth() {
        return width;
    }

    ElementTab::~ElementTab() {

    }
    
    void ElementTab::chgList(int i, Element* e) {
         
            if(list[i]==NULL) list[i]=unique_ptr<Element>(e);
                       
    }

    void ElementTab::chgList2(int i, int j) {

        if(int(list.size())>=i&&int(list.size())>=j){
            if(list[i]!=NULL){
                if(list[j]==NULL) {
                list[j].swap(list[i]);
                }
            }
            else std::cout << "Erreur sur le deplacement !" << std::endl;
        }
         else std::cout << "Deplacement hors list" << std::endl;
    }

       void ElementTab::createElementCsv(std::vector<int> carte){
        std::ifstream fichier;
            
    	
      
            fichier.open("res/map2.csv",std::ios::in);
            if(!fichier.good())
                 throw std::runtime_error("Error opening!!");
                 std::string ligne,valeur;
       
       // int i = 0;
		
        while(!fichier.eof()){
            std::getline(fichier,ligne);
            std::stringstream stream(ligne);
            std::cout << ligne << std::endl;

		
            while(getline(stream, valeur,',')){
			
                carte.push_back(atoi(valeur.c_str()));
			
            }
        }
    
        for(int i=0; i<int(carte.size()) ; i++){
            if(carte[i]==-1) {
                list.push_back(NULL);
            }
            if(carte[i]==0) {
                list.push_back(std::unique_ptr<Element>(new Champdebataille(HERBE)));
            }
           if(carte[i]==1){
                
                list.push_back(std::unique_ptr<Element>(new Champdebataille(ROUTE)));
            }
            
            if(carte[i]==2){
                list.push_back(std::unique_ptr<Element>(new Champdebataille(SABLE)));
            }
            
            if(carte[i]==3){ 
                list.push_back(std::unique_ptr<Element>(new Champdebataille(EAU)));
            }
            
            if(carte[i]==4){
                list.push_back(std::unique_ptr<Element>(new Champdebataille(ROCHER)));
            }
            if(carte[i]==5){
                list.push_back(std::unique_ptr<Element>(new Batiment(CASERNE)));
            }
            
            if(carte[i]==6){
                list.push_back(std::unique_ptr<Element>(new Batiment(QG)));
            }
            else{
                list.push_back(NULL);
                }  
    
        }  
    
    }
       
       
         Heli::Heli() {
        
    
    }

    
    

    TypeId Heli::getTypeId() const {
        return TypeId(3);
    }

     
    Heli::~Heli() {

    }
 
     int Heli::diffUnite() {
         return 1;
    }
     
     
     Infanterie::Infanterie(){
        this->pdv=10;
        
    }
    

    int Infanterie::diffUnite() {
        return 0;
    }
    
    TypeId Infanterie::getTypeId() const {
        return TypeId(2);
    }

    
    

    Infanterie::~Infanterie() {

    }
    
    MobileElement::MobileElement(){
    
    }

    int MobileElement::getAttaque() const {
        return attaque;
    }

    int MobileElement::getMouvement() const {
        return mouvement;
    }

    int MobileElement::getDefense() const {
        return defense;
    }

    int MobileElement::getPdv() const {
        return pdv;
    }

    int MobileElement::getPosition() const {
        return position;
       
    }

    void MobileElement::setAttaque(int attaque) {
        this ->attaque=attaque;
    }

    void MobileElement::setDefense(int defense) {
         this ->defense=defense;
    }

    void MobileElement::setMouvement(int mouvement) {
         this ->mouvement=mouvement;
    }

    void MobileElement::setPdv(int pdv) {
         this ->pdv=pdv;
    }

    void MobileElement::setPosition(int position) {
         this ->position=position;
    }

    MobileElement::~MobileElement() {

    }
    

    bool MobileElement::isStatic() const {
        return false;
    }
    
    State::State() {

    }

 
    ElementChars* State::getChars() {
        return chars;
    }

    ElementTab* State::getGrid() {
        return grid;
    }
    
    
    StaticElement::StaticElement() {

    }
    
    StaticElement::~StaticElement() {

    }

    
    bool StaticElement::isStatic() const {
        return true;
    }

    Tank::Tank(){
    
    }

    int Tank::diffUnite() {
        return 2;
    }
  

    TypeId Tank::getTypeId() const {
        return TypeId(4);
    }


    Tank::~Tank() {

    }