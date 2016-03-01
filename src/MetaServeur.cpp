#include "../include/MetaServeur.h"
#include <iostream>
#include <Ice/Ice.h>


MetaServer::MetaServer(){
    Ice::CommunicatorPtr ic;
    try {
	ic = Ice::initialize();
	Ice::ObjectPrx obj = ic->stringToProxy("BiblAudio:tcp -p 10000");
	servA = biblAudio::ServeurIcePrx::checkedCast(obj);
	if(!servA)std::cerr << "servA not found\n";
    } catch (const Ice::Exception& e) {
	std::cerr << e << '\n';
    }


}


biblAudio::Morceau MetaServer::bRechercherMorceau( const std::string &sNomMusique, const Ice::Current&)
{
    /*biblAudio::Morceau a;
      std::map< std::string, biblAudio::Morceau >::const_iterator it;
      it = mmapMorceaux.find( sNomMusique );
      if( it != mmapMorceaux.end() )
      {

      return (*it).second;
      }
      return a;*/
}


biblAudio::mvectRecherche MetaServer::getMorceauxMorc( const std::string &sNomMorc, const Ice::Current& )
{
    /*mvectRecherche.clear();
      for( biblAudio::mmapMorceaux::iterator it = mmapMorceaux.begin(); it != mmapMorceaux.end(); ++it )
      {
      if( ( (*it) . second ).msNomMorceau == sNomMorc )
      {
      mvectRecherche.push_back( (*it) . second );
      }
      }
      return mvectRecherche;*/
}


biblAudio::mvectRecherche MetaServer::getMorceauxArt( const std::string &sNomArtiste, const Ice::Current& )
{
    /*mvectRecherche.clear();
      for( biblAudio::mmapMorceaux::iterator it = mmapMorceaux.begin(); it != mmapMorceaux.end(); ++it )
      {
      if( ( (*it) . second ).msNomArtiste == sNomArtiste )
      {
      mvectRecherche.push_back( (*it) . second );
      }
      }
      return mvectRecherche;*/
}


void MetaServer::afficherMorceaux(const Ice::Current&)
{
    /*for( biblAudio::mmapMorceaux::const_iterator it = mmapMorceaux.begin(); it != mmapMorceaux.end(); ++it )
      {
      std::cout << (*it) .first <<"\n";
      }*/
}

bool MetaServer::bAjoutMorceau(const std::string &sNomArt, const  std::string &sNomMorc, const  std::string &sFic,  int uiDureeMorc , int uiDateSortie, const Ice::Current&){
    /*biblAudio::Morceau morceau;
      morceau.msFichier = sFic;
      morceau.msNomArtiste = sNomMorc;
      morceau.msNomMorceau = sNomArt;
      morceau.muiDateSortie = uiDateSortie;
      morceau.muiDureeMorceau = uiDureeMorc;
      mmapMorceaux . insert( std::pair< std::string, biblAudio::Morceau > ( sNomArt, morceau ) );
      return true;*/
}

bool MetaServer::bSuprMorceau( const std::string &sNomArt,const std::string &sNomMorc , const Ice::Current&){
    /*	biblAudio::mmapMorceaux::iterator it;
	it = mmapMorceaux.find( sNomMorc );

	for( biblAudio::mmapMorceaux::iterator it = mmapMorceaux.begin(); it != mmapMorceaux.end(); ++it ){
	if((*it).first == sNomMorc && (*it).second.msNomArtiste == sNomArt)
	{
	mmapMorceaux.erase(it);
	return true;
	}
	}
	return false;
     */
}

void MetaServer::prepareSong()
{
}

void MetaServer::readSoundFic(const std::string &pathToFic,const Ice::Current&)
{
	servA->readSoundFic( pathToFic );
}

void MetaServer::readSound(const std::string &sNomMorceau,const std::string &sNomArtiste,const Ice::Current& iceCurrent)
{
    /*	mvectRecherche = getMorceauxArt( sNomArtiste, iceCurrent );
	biblAudio::Morceau morc = rechercherMorceauVect( mvectRecherche , sNomMorceau);
	if(morc.msNomMorceau == "erreur")return; 
     */
}

biblAudio::Morceau MetaServer::rechercherMorceauVect( biblAudio::mvectRecherche mvectMorc,const std::string &nomMorc )
{
    for(unsigned int i = 0;i<mvectMorc.size();i++)
    {
	if(mvectMorc[i].msNomMorceau == nomMorc)
	    return mvectMorc[i];
    }
    biblAudio::Morceau a;
    a.msNomMorceau = "erreur";
    return a;
}

void MetaServer::stopSound(const Ice::Current&)
{
}

MetaServer::~MetaServer(){
}
