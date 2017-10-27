
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
 

#ifndef TOUTESLESFONCTIONS_H
#define TOUTESLESFONCTIONS_H

    CharsTileSet ();
    const std::string  getImageFile () const;
    const Tile&  getTile (const state::Element& e) const;
     GridTileSet ();
    const std::string  getImageFile () const;
    const Tile&  getTile (const state::Element& e) const;
    Tile (int x, int y, int w, int h);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
      virtual const std::string  getImageFile () const = 0;
    virtual const Tile& getTile (const state::Element& e) const = 0;
     bool load (const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);
    std::vector<int> lirefichiercsv (std::vector<int> carte);
    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    void loadTexture (const std::string& image_file);
    void initQuads (int count);
    void setSpriteLocation (int i, int x, int y);
    void setSpriteTexture (int i, const Tile& tex);
      Batiment ();
    Batiment (BatimentTypeId id);
    bool isChampdebataille () const;
    TypeId getTypeId () const;
    int getCapture () const;
    void setCapture (int capture);
    // Setters and Getters
    BatimentTypeId getBatimentTypeId() const;
    void setBatimentTypeId(BatimentTypeId batimentTypeId);
        Champdebataille ();
    Champdebataille (ChampdebatailleTypeId id);
    bool isChampdebataille () const;
    TypeId getTypeId () const;
    // Setters and Getters
    ChampdebatailleTypeId getChampdeBatailleType() const;
    void setChampdeBatailleType(ChampdebatailleTypeId champdeBatailleType);
     virtual TypeId getTypeId () const = 0;
    virtual bool isStatic () const = 0;
    void setType (int type);
    int getType ();
    // Setters and Getters
    void setTypeId(TypeId typeId);
        Element ( );
            ElementChars ();
    void ElementToCarte (const state::Element& e);
    ElementTab ();
    ElementTab (size_t width, size_t height);
    size_t getWidth ();
    size_t getHeight ();
    Element* getElement (int i, int j) const;
    void setElement (Element* e);
    int sizeList ();
    void chgList (int i, Element* e);
    void chgList2 (int i, int j);
    void  createElementCsv (std::vector<int> carte);
    // Setters and Getters
    const std::vector<std::unique_ptr<Element> >& getList() const;
    void setList(const std::vector<std::unique_ptr<Element> >& list);
    Heli ();
    int diffUnite ();
    TypeId getTypeId () const;
    // Setters and Getters
    HeliTypeId getHeliTypeId() const;
    void setHeliTypeId(HeliTypeId heliTypeId);
        Infanterie ();
    int diffUnite ();
    TypeId getTypeId () const;
    // Setters and Getters
    InfanterieTypeId getInfanterieTypeId() const;
    void setInfanterieTypeId(InfanterieTypeId infanterieTypeId);
    MobileElement ( );
    virtual int diffUnite () = 0;
    bool isStatic () const;
    // Setters and Getters
    int getPosition() const;
    void setPosition(int position);
    int getPdv() const;
    void setPdv(int pdv);
    int getMouvement() const;
    void setMouvement(int mouvement);
    int getDefense() const;
    void setDefense(int defense);
    int getAttaque() const;
    void setAttaque(int attaque);
        State ();
    ElementTab* getGrid ();
    ElementChars* getChars ();
        StaticElement ();
    bool isStatic () const;
    virtual bool isChampdebataille () const = 0;
       Tank ();
    int diffUnite ();
    TypeId getTypeId () const;
    // Setters and Getters
    TankTypeId getTankTypeId() const;
    void setTankTypeId(TankTypeId tankTypeId);
    
    
    
    
    

#endif /* TOUTESLESFONCTIONS_H */


