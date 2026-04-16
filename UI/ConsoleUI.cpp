#include "ConsoleUI.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

ConsoleUI::ConsoleUI(int width)
	: Width(width)
{

}

void ConsoleUI::ClearScreen() const
{
	system("cls");
}

void ConsoleUI::DrawTitle(const std::string& title) const
{
	DrawSeparator();
	DrawCentered(title);
	DrawSeparator();
}

void ConsoleUI::DrawSeparator() const
{
	std::cout << std::string(Width, '=') << "\n";
}

void ConsoleUI::DrawText(const std::string& text) const
{
	std::cout << text << "\n";
}

void ConsoleUI::DrawCentered(const std::string& text) const
{
	std::cout << CenterText(text) << "\n";
}

void ConsoleUI::DrawBoxed(const std::string& text) const
{
	int inner = Width - 4;

	std::string t = text;
	if (t.length() > inner)
		t = t.substr(0, inner);

	int pad = (inner - t.length()) / 2;

	std::cout << "| "
		<< std::string(pad, ' ')
		<< t
		<< std::string(inner - pad - t.length(), ' ')
		<< " |\n";
}

void ConsoleUI::DrawMenu(const std::vector<std::string>& options) const
{
	for (size_t i = 0; i < options.size(); i++)
	{
		std::cout << i + 1 << ". " << options[i] << "\n";
	}
}

void ConsoleUI::PlayerActionAnimation(const std::string& Action)
{
	for (int i = 1; i <= 3; i++)
	{
		std::cout << "\r" << Action << std::string(i, '.') << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}
	std::cout << "\n";
}

std::string ConsoleUI::CenterText(const std::string& text) const
{
	int padding = (Width - text.length()) / 2;
	if (padding < 0) padding = 0;

	return std::string(padding, ' ') + text;
}
