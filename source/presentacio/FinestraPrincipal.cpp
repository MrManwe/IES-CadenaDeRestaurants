#include "FinestraPrincipal.h"
#include "dades/BaseDeDades.h"
#include "domini/transaccions/TxLlistaMenusVegetarians.h"
#include "domini/transaccions/TxCrearMenu.h"
#include "domini/Excepcions.h"
#include "dades/Excepcions.h"
#include <set>

namespace presentacio
{
	//////////////////////////////////////////////////////////////////////////////////

	FinestraPrincipal::FinestraPrincipal(const juce::String& name, juce::LookAndFeel& i_lookAndFeel) 
		: juce::DocumentWindow(name,i_lookAndFeel.findColour(juce::ResizableWindow::ColourIds::backgroundColourId),juce::DocumentWindow::allButtons)
		, m_tabsComponent(juce::TabbedButtonBar::TabsAtTop)
		, m_llistarMenusComponent(i_lookAndFeel)
		, m_crearMenuComponent(i_lookAndFeel)
	{
		setUsingNativeTitleBar(true);

		m_tabsComponent.addTab("LListar Menus Vegetarians", i_lookAndFeel.findColour(juce::ResizableWindow::ColourIds::backgroundColourId), &m_llistarMenusComponent, false);
		m_tabsComponent.addTab("Crear Menu", i_lookAndFeel.findColour(juce::ResizableWindow::ColourIds::backgroundColourId), &m_crearMenuComponent, false);
		m_tabsComponent.setSize(600, 600);
		setContentNonOwned(&m_tabsComponent, true);
		centreWithSize(600, 600);
		setVisible(true);
	}

	void FinestraPrincipal::closeButtonPressed()
	{
		juce::JUCEApplication::getInstance()->systemRequestedQuit();
	}

	//////////////////////////////////////////////////////////////////////////////////

	FinestraPrincipal::LListaMenusVegetariansComponent::LListaMenusVegetariansComponent(juce::LookAndFeel& i_lookAndFeel)
	{
		addAndMakeVisible(m_llistaMenusVegetariansButton);
		m_llistaMenusVegetariansButton.setButtonText("Llista Menus Vegetarians");
		m_llistaMenusVegetariansButton.addListener(this);
		m_llistaMenusVegetariansButton.setLookAndFeel(&i_lookAndFeel);

		addAndMakeVisible(m_adrecaLabel);
		m_adrecaLabel.setText("Adreca:", juce::dontSendNotification);
		m_adrecaLabel.setLookAndFeel(&i_lookAndFeel);
		m_adrecaLabel.setJustificationType(juce::Justification::right);

		addAndMakeVisible(m_adrecaText);
		m_adrecaText.setText("Carrer1");
		m_adrecaText.setLookAndFeel(&i_lookAndFeel);
		m_adrecaText.setJustification(juce::Justification::left);

		setSize(600, 600);
	}

	FinestraPrincipal::LListaMenusVegetariansComponent::~LListaMenusVegetariansComponent()
	{

	}

	void FinestraPrincipal::LListaMenusVegetariansComponent::resized()
	{
		//int height = getHeight();
		int width = getWidth();
		int itemHeight = 30;
		int separatorSize = 5;

		m_adrecaLabel.setTopLeftPosition(0, 0);
		m_adrecaLabel.setSize(width / 2, itemHeight);

		m_adrecaText.setTopLeftPosition(width / 2, 0);
		m_adrecaText.setSize(width / 2, itemHeight);
		
		m_llistaMenusVegetariansButton.setTopLeftPosition(0, itemHeight + separatorSize);
		m_llistaMenusVegetariansButton.setSize(width, itemHeight);
	}

	void FinestraPrincipal::LListaMenusVegetariansComponent::buttonClicked(juce::Button* i_buttonPressed)
	{
		//Aquí arriba l'esdeveniment
		if (i_buttonPressed == &m_llistaMenusVegetariansButton)
		{
			std::string adreca = m_adrecaText.getText().toStdString();
			try
			{
				domini::TxLlistaMenusVegetarians llistarMenusVegetarians(adreca);
				llistarMenusVegetarians.Executar();
				std::set<domini::DadesMenu> menusVegetarians = llistarMenusVegetarians.ObteResultat();
				
				std::stringstream ss;
				for (domini::DadesMenu menu : menusVegetarians)
				{
					ss << "[" << menu.nom << ", " << menu.preu << ", " << menu.estalvi << "]" << std::endl;
				}

				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::InfoIcon, "Menus Vegetarians", ss.str().c_str(), nullptr);
			}
			catch (dades::RestaurantNoExisteix pe)
			{
				std::string message = "El Restaurant amb adreca [" + adreca +"] no existeix";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
		}
	}

	FinestraPrincipal::CrearMenuComponent::CrearMenuComponent(juce::LookAndFeel& i_lookAndFeel)
	{
		addAndMakeVisible(m_crearMenuButton);
		m_crearMenuButton.setButtonText("Crear Menu");
		m_crearMenuButton.setLookAndFeel(&i_lookAndFeel);
		m_crearMenuButton.addListener(this);

		Init("Adreca:", m_adrecaLabel, i_lookAndFeel);
		Init("Carrer1", m_adrecaText, i_lookAndFeel);
		
		Init("Nom: ", m_nomLabel, i_lookAndFeel);
		Init("Nou Menu", m_nomText, i_lookAndFeel);

		Init("Preu: ", m_preuLabel, i_lookAndFeel);
		Init("0.0", m_preuText, i_lookAndFeel);

		addAndMakeVisible(m_infantilToggle);
		m_infantilToggle.setButtonText("Infantil");
		m_infantilToggle.setLookAndFeel(&i_lookAndFeel);

		Init("Plat: ", m_nomPlatLabel, i_lookAndFeel);
		Init("Pizza Barbacoa", m_nomPlatText, i_lookAndFeel);

		Init("Beguda: ", m_nomBegudaLabel, i_lookAndFeel);
		Init("Vi rosat", m_nomBegudaText, i_lookAndFeel);

		Init("Postre: ", m_nomPostreLabel, i_lookAndFeel);
		Init("Bola de Vainilla", m_nomPostreText, i_lookAndFeel);

		setSize(600, 600);
	}

	FinestraPrincipal::CrearMenuComponent::~CrearMenuComponent()
	{

	}

	void FinestraPrincipal::CrearMenuComponent::resized()
	{
		//int height = getHeight();
		int width = getWidth();
		int itemHeight = 30;
		int separatorSize = 15;

		int y = 0;
		m_adrecaLabel.setTopLeftPosition(0, y);
		m_adrecaLabel.setSize(width / 2, itemHeight);
		m_adrecaText.setTopLeftPosition(width / 2, y);
		m_adrecaText.setSize(width / 2, itemHeight);

		y+= itemHeight + separatorSize;
		m_nomLabel.setTopLeftPosition(0, y);
		m_nomLabel.setSize(width / 2, itemHeight);
		m_nomText.setTopLeftPosition(width / 2, y);
		m_nomText.setSize(width / 2, itemHeight);

		y += itemHeight + separatorSize;
		m_preuLabel.setTopLeftPosition(0, y);
		m_preuLabel.setSize(width / 2, itemHeight);
		m_preuText.setTopLeftPosition(width / 2, y);
		m_preuText.setSize(width / 2, itemHeight);

		y += itemHeight + separatorSize;
		m_infantilToggle.setTopLeftPosition(width/2, y);
		m_infantilToggle.setSize(width / 2, itemHeight);
		

		y += itemHeight + separatorSize;
		m_nomPlatLabel.setTopLeftPosition(0, y);
		m_nomPlatLabel.setSize(width / 2, itemHeight);
		m_nomPlatText.setTopLeftPosition(width / 2, y);
		m_nomPlatText.setSize(width / 2, itemHeight);

		y += itemHeight + separatorSize;
		m_nomBegudaLabel.setTopLeftPosition(0, y);
		m_nomBegudaLabel.setSize(width / 2, itemHeight);
		m_nomBegudaText.setTopLeftPosition(width / 2, y);
		m_nomBegudaText.setSize(width / 2, itemHeight);

		y += itemHeight + separatorSize;
		m_nomPostreLabel.setTopLeftPosition(0, y);
		m_nomPostreLabel.setSize(width / 2, itemHeight);
		m_nomPostreText.setTopLeftPosition(width / 2, y);
		m_nomPostreText.setSize(width / 2, itemHeight);

		y += itemHeight + separatorSize;
		m_crearMenuButton.setTopLeftPosition(0, y);
		m_crearMenuButton.setSize(width, itemHeight);
	}

	void FinestraPrincipal::CrearMenuComponent::buttonClicked(juce::Button* i_buttonPressed)
	{
		//Aquí arriba l'esdeveniment
		if (i_buttonPressed == &m_crearMenuButton)
		{
			std::string adreca = m_adrecaText.getText().toStdString();
			std::string nom = m_nomText.getText().toStdString();
			float preu = m_preuText.getText().getFloatValue();
			bool infantil = m_infantilToggle.getToggleState();
			std::string nomPlat = m_nomPlatText.getText().toStdString();
			std::string nomBeguda = m_nomBegudaText.getText().toStdString();
			std::string nomPostre = m_nomPostreText.getText().toStdString();
			try
			{
				domini::TxCrearMenu crearMenu(adreca, nom, preu, nomPlat, nomPostre, nomBeguda, infantil);
				crearMenu.Executar();

				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::InfoIcon, "Menus Vegetarians", "Menu inserit correctament", nullptr);
			}
			catch (dades::RestaurantNoExisteix pe)
			{
				std::string message = "El Restaurant amb adreca [" + adreca + "] no existeix";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
			catch (dades::PlatNormalNoExisteix pe)
			{
				std::string message = "El Plat Normal amb nom [" + nomPlat + "] no existeix";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
			catch (dades::PostrelNoExisteix pe)
			{
				std::string message = "El Postre Normal amb nom [" + nomPostre + "] no existeix";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
			catch (dades::BegudaNoExisteix pe)
			{
				std::string message = "La Beguda amb nom [" + nomBeguda + "] no existeix";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
			catch (domini::JaExisteixProducte pe)
			{
				std::string message = "El Prodcute amb nom [" + nom + "] ja existeix";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
			catch (domini::MassaProductes pe)
			{
				std::string message = "El Postre amb nom [" + nomPostre + "] esta a massa menus";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
			catch (domini::MenuInfantilIncorrecte pe)
			{
				std::string message = "El Menu no pot ser infantil i contenir una baguda alcoholica";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
			catch (domini::RestaurantNoOfereixBeguda pe)
			{
				std::string message = "El Restaurant amb adreca [" + adreca + "]no ofereix la beguda [" + nomBeguda + "]";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
			catch (domini::PreuIncorrecte pe)
			{
				std::string message = "El preu del menu es superior a la suma de tots els plats";
				juce::NativeMessageBox::showMessageBox(juce::AlertWindow::AlertIconType::WarningIcon, "Error!", message.c_str(), nullptr);
			}
		}
	}

	void FinestraPrincipal::CrearMenuComponent::Init(const std::string& i_text, juce::Label& i_label, juce::LookAndFeel& i_lookAndFeel)
	{
		addAndMakeVisible(i_label);
		i_label.setText(i_text.c_str(), juce::dontSendNotification);
		i_label.setJustificationType(juce::Justification::right);
		i_label.setLookAndFeel(&i_lookAndFeel);
	}

	void FinestraPrincipal::CrearMenuComponent::Init(const std::string& i_text, juce::TextEditor& i_textEditor, juce::LookAndFeel& i_lookAndFeel)
	{
		addAndMakeVisible(i_textEditor);
		i_textEditor.setText(i_text.c_str());
		i_textEditor.setJustification(juce::Justification::left);
		i_textEditor.setLookAndFeel(&i_lookAndFeel);
	}
}



using namespace std;








class EmpleatUniversitari 
{
public:
	string nom;
	float souBase;

	virtual float pagarSou()
	{
		return souBase;
	}
};

class Professor: public EmpleatUniversitari
{
public:
	float plusLLoc;

	float pagarSou() override
	{
		return souBase + plusLLoc;
	}
};

class Administratiu : public EmpleatUniversitari
{
public:
	int horesExtra;
	float preuHoraExtra;

	float pagarSou() override
	{
		return souBase + horesExtra * preuHoraExtra;
	}
};

using namespace std;
struct Data {};


class Animal
{
private:
	string nom;
public:
	string GetNom() {
		return nom;
	}
};

class Persona
{
private:
	set<Animal*> mascotes;
public:
	set<string> LlistaNomAnimals(){
		set<string> nomAnimals;
		for (Animal* a : mascotes){
			nomAnimals.insert(a->GetNom());
		}
		return nomAnimals;
	}
};

