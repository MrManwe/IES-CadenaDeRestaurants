#pragma once
#include <juce_gui_basics/juce_gui_basics.h>

namespace presentacio
{
	class FinestraPrincipal : public juce::DocumentWindow
	{
	public:
		FinestraPrincipal(const juce::String& name, juce::LookAndFeel& i_lookAndFeel);
		void closeButtonPressed() override;

	private:
		class LListaMenusVegetariansComponent : public juce::Component, public juce::Button::Listener
		{
		public:
			LListaMenusVegetariansComponent(juce::LookAndFeel& i_lookAndFeel);
			~LListaMenusVegetariansComponent();
			void resized() override;

			void buttonClicked(juce::Button*) override;

		private:
			juce::Label m_adrecaLabel;
			juce::TextEditor m_adrecaText;
			juce::TextButton m_llistaMenusVegetariansButton;
		};

		class CrearMenuComponent : public juce::Component, public juce::Button::Listener
		{
		public:
			CrearMenuComponent(juce::LookAndFeel& i_lookAndFeel);
			~CrearMenuComponent();
			void resized() override;

			void buttonClicked(juce::Button*) override;

		private:
			void Init(const std::string& i_text, juce::Label& i_label, juce::LookAndFeel& i_lookAndFeel);
			void Init(const std::string& i_text, juce::TextEditor& i_textEditor, juce::LookAndFeel& i_lookAndFeel);
			juce::Label m_adrecaLabel;
			juce::TextEditor m_adrecaText;
			
			juce::Label m_nomLabel;
			juce::TextEditor m_nomText;

			juce::Label m_preuLabel;
			juce::TextEditor m_preuText;

			juce::ToggleButton m_infantilToggle;

			juce::Label m_nomPlatLabel;
			juce::TextEditor m_nomPlatText;
			
			juce::Label m_nomBegudaLabel;
			juce::TextEditor m_nomBegudaText;

			juce::Label m_nomPostreLabel;
			juce::TextEditor m_nomPostreText;

			juce::TextButton m_crearMenuButton;
		};

	private:
		LListaMenusVegetariansComponent m_llistarMenusComponent;
		CrearMenuComponent m_crearMenuComponent;
		juce::TabbedComponent m_tabsComponent;
	};
}