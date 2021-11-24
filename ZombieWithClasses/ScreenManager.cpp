#include "ScreenManager.h"
#include "Stage.h"
#include "MainMenuState.h"
using namespace Managers;

ScreenManager::ScreenManager(GraphicManager* gm, Entities::Characters::PlayerOne* p1, Entities::Characters::PlayerTwo* p2) :
    GM{ *gm }, player1{ p1 }, player2{ p2 } {
    push(new States::MainMenuState(GM));
}

bool ScreenManager::processCode(int returnCode) {
    switch (returnCode) {
    case end:
        return true;
    case goRacoonCity:
        push(new States::Stage(&GM, player1, player2));
        return false;
        break;
        /*case goFirstStage:
        {
            RacoonCity* fase = new FaseExemplo(gerenciadorGrafico, jogador1);
            fase->inicializar();
            push(fase);
            return false;
        }
        case salvarJogo:
        {
            pop();
            Fase* fase = dynamic_cast<Fase*>(top());
            if (!fase)
                std::cout << "Erro! Não há fase a ser salva." << std::endl;
            else if (!fase->salvar("../jogos-salvos/jogo_salvo.json"))
                std::cout << "Erro! O jogo não pôde ser salvo." << std::endl;
            return false;
        }
        case carregarJogo:
        {
            std::cout << "como";
            FaseExemplo* fase = new FaseExemplo(gerenciadorGrafico, jogador1);
            std::cout << " onde" << std::endl;
            try {
                fase->carregar("../jogos-salvos/jogo_salvo.json");
                push(fase);
            } catch (char const* s) {
                std::cout << s << std::endl;
                delete fase;
            }
            return false;
        }
        case irMenuPausa:
            push(new MenuPausa(gerenciadorGrafico));
            return false;

        case sairMenuPausa:
            pop();
            return false;

        case irMenuPrincipal:
            esvaziarPilha();
            push(new MenuPrincipal(gerenciadorGrafico));

        case continuar:*/
    default:
        return false;
    }
}
