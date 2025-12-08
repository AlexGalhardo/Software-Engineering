import React, { useState } from 'react'
import { Box } from '@site/src/algorithms/ui/box/box'
import Translate from '@docusaurus/Translate'
import styles from './styles.module.css'
import { Debugger } from '../../ui/debugger/debugger'

interface BinaryArraySearchProps {
  array: number[]
  element: number
}

interface Version {
  mid: number
  low: number
  high: number
  returnValue: null | number
  eliminatedIndexes: number[]
}

export function BinaryArraySearch({ array, element }: BinaryArraySearchProps) {
  const [versions, setVersions] = useState<Version[]>([
    {
      mid: -1,
      low: 0,
      high: array.length - 1,
      returnValue: null,
      eliminatedIndexes: [],
    }
  ])

  const currentVersion = versions[versions.length - 1]

  const handleNext = () => {
    if (currentVersion && currentVersion.low <= currentVersion.high) {
      const mid = Math.floor((currentVersion.low + currentVersion.high) / 2)

      const eliminatedIndexes: number[] = []

      for (let i = 0; i < array.length; i++) {
        if (i < currentVersion.low || i > currentVersion.high) {
          eliminatedIndexes.push(i)
        }
      }
      if (array[mid] === element) {
        const newVersion: Version = {
          ...currentVersion,
          mid,
          returnValue: mid,
          eliminatedIndexes
        }
        setVersions(prevVersions => [...prevVersions, newVersion])
      } else if (array[mid] > element) {
        const newVersion: Version = {
          ...currentVersion,
          high: mid - 1,
          mid: Math.floor((currentVersion.low + currentVersion.high) / 2),
          eliminatedIndexes
        }
        setVersions(prevVersions => [...prevVersions, newVersion])
      } else {
        const newVersion: Version = {
          ...currentVersion,
          low: mid + 1,
          mid: Math.floor((currentVersion.low + currentVersion.high) / 2),
          eliminatedIndexes
        }
        setVersions(prevVersions => [...prevVersions, newVersion])
      }
    } else {
      const newVersion: Version = {
        ...currentVersion,
        returnValue: -1,
      }
      setVersions(prevVersions => [...prevVersions, newVersion])
    }
  }

  const handlePrevious = () => {
    if (versions.length > 1) {
      setVersions(versions.slice(0, -1))
    }
  }

  const isNextButtonDisabled = currentVersion && currentVersion.returnValue !== null
  const isPreviousButtonDisabled = versions.length === 1

  return (
    <div style={{ display: 'flex', gap: '2rem' }}>
      <div style={{ flexGrow: 1 }}>
        <div className={styles.boxContainer}>
          {array.map((value, index) => (
            <div key={index} className={styles.boxItemsContainer}>
              <p style={{ marginBottom: 0 }}>{index}</p>
              <Box
                isCurrent={currentVersion && index === currentVersion.mid}
                isDisabled={currentVersion && currentVersion.eliminatedIndexes.includes(index)}
                isActive={currentVersion && element === array[currentVersion.mid] && element === array[index]}
                size="sm"
              >
                {value}
              </Box>
            </div>
          ))}
        </div>
        <div className={styles.buttonContainer}>
          <button className="button button--secondary" onClick={handlePrevious} disabled={isPreviousButtonDisabled}>
            <Translate id="algorithm.actions.previous">
              Previous
            </Translate>
          </button>
          <button className="button button--secondary" onClick={handleNext} disabled={isNextButtonDisabled}>
            <Translate id="algorithm.actions.next">
              Next
            </Translate>
          </button>
        </div>
        <div>
          <p>
            {versions.length === 1 ? (
              <Translate id="algorithm.actions.startDescription">
                Click on next to start the algorithm.
              </Translate>
            ) : (
              <>
                <Translate id="algorithm.binarySearchArray.isItEqual_1">The array item at mid index (</Translate>
                {currentVersion && array[currentVersion.mid]}
                <Translate id="algorithm.binarySearchArray.isItEqual_2">) is it equal to the target</Translate>
                ({element})?
              </>
            )}
          </p>
          <p>
          {versions.length === 1 ? (
            <Translate id="algorithm.actions.stepLogicDescription">
              The logic for each step will be displayed here.
            </Translate>
          ) : array[currentVersion.mid] > element && !currentVersion.returnValue ? (
            <Translate id="algorithm.binarySearchArray.biggerThan">
              No, it's bigger than the element we're searching, so we will update the high variable with mid - 1. This
              step eliminates every position after mid, since the element it's not there.
            </Translate>
          ) : array[currentVersion.mid] < element && !currentVersion.returnValue ? (
            <Translate id="algorithm.binarySearchArray.smallerThan">
              No, it's smaller than the element we're searching, so we will update the low variable with mid + 1. This
              step eliminates every position before mid, since the element it's not there.
            </Translate>
          ) : array[currentVersion.mid] === element ? (
            <>
              <Translate id="algorithm.binarySearchArray.elementFound">Yes, return the mid index </Translate>
              ({currentVersion.mid}).
            </>
          ) : (
            <Translate id="algorithm.binarySearchArray.elementNotFound">
              The target number is not in the array. Return -1.
            </Translate>
          )}
          </p>
        </div>
      </div>
      <div style={{ width: 256.53 }}>
        <h3>Debugger</h3>
        <Debugger>
          <p>--------------------------</p>
          {currentVersion && <p>low: {versions.length === 1 ? currentVersion.low : versions[versions.length - 2].low}</p>}
          {currentVersion && <p>high: {versions.length === 1 ? currentVersion.high : versions[versions.length - 2].high}</p>}
          {currentVersion && currentVersion.mid > -1 ? <p>mid: {currentVersion.mid}</p> : <p>mid: null</p>}
          {currentVersion && <p>return value: {currentVersion.returnValue ?? 'pending'}</p>}
          <p>--------------------------</p>
        </Debugger>
      </div>
    </div>
  )
}
